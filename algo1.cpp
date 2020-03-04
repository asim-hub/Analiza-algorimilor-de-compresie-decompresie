#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include<fstream>
using namespace std;


struct Node
{
   	int fr;
	char c;
	Node *left, *right;
};
Node* getNode(char c, int fr, Node* left, Node* right)
{
	Node* node = new Node();

	node->c = c;
	node->fr = fr;
	node->left = left;
	node->right = right;

	return node;
}

struct compare
{
  bool operator()(Node *left, Node* right)
  {
      return left->fr > right->fr;
  }
};

void decode(Node* root, int &index, string comprim ,FILE *f )
{	
	//ILE *f = fopen("outdecomprim.bin", "w");
	if (root == nullptr) {
		return;
	}

	// nod frunza
	if (!root->left && !root->right)
	{
		//cout << root->c;
		fputc(root->c,f);
		return;
	}

	index++;

	if (comprim[index] =='0')
		decode(root->left, index, comprim ,f);
	else
		decode(root->right, index, comprim, f);
}

void code(Node* root, string s,unordered_map<char, string> &huffmanCode)
{
	if (root == NULL)
		return;

	// nod frunza
	if (!root->left && !root->right) {
		huffmanCode[root->c] = s;
	}

	code(root->left, s + "0", huffmanCode);
	code(root->right, s + "1", huffmanCode);
}

void writeBinary(string comprim){
	ofstream out;
	FILE *file = fopen("outcomprim.bin", "wb");
	uint8_t c = 0;
	int Bit_Counter=0;
	for(int i = 0; i < comprim.size(); ++i)
	{
		if(comprim[i] == '1')
		{
			c |= 1;
		}

		if(i < comprim.size()-1)
		{
			c <<= 1;
		}

		++Bit_Counter;

		if(Bit_Counter == 8)
		{
			putc(c,file);
			c=0;
			Bit_Counter = 0;
		}
	}
}

void buildTree(string text_in){
   unordered_map<char, int> umap;
   for (int i = 0; i < text_in.length();i++){
      umap[text_in[i]]++;
   }

   priority_queue<Node*, vector<Node*>, compare> queue;

   for (auto elem: umap) {
      
		queue.push(getNode(elem.first, elem.second, NULL, NULL));
	}

   while (queue.size() != 1)
	{
		// sterg nodurile cu prioritatea cea mai mare
		Node *left = queue.top(); queue.pop();
		Node *right = queue.top();	queue.pop();

		// creez un nod intern cu cele doua noduri
		// avand copii cele doua noduri, iar frecenta egala cu suma frecvenetlor
		// adaug nodul in coada
		int sum = left->fr + right->fr;
		queue.push(getNode('\0', sum, left, right));
	}
   Node* root = queue.top();

   unordered_map<char, string> huffmanCode;
   code(root, "", huffmanCode);

   string comprim = "";
	for (char ch: text_in) {
		comprim += huffmanCode[ch];
	}
	
	//aici scriu in fisier binar ce am in comprim
	writeBinary(comprim);
	FILE *f = fopen("outdecomprim.txt", "w");
    int index = -1;
	while (index < (int)comprim.size() - 2) {
		decode(root, index, comprim, f);
	}
	
}
int main(int argc, char *argv[]) {
	
 	string text_in;
	vector<string> vecstr;
	ifstream fin(argv[1], ios_base::in);
    if (fin.is_open())
    {
        char* buffer = new char[1024];
        while (fin.read(buffer, 1024))
        {
            string s(buffer);
            vecstr.push_back(s);
        }
        string s(buffer, fin.gcount());
        vecstr.push_back(s);

        delete[] buffer;
        fin.close();
    }
    else
    {
 	    cerr << "Cannot open file:" << argv[1] << endl;
    }
    for (int i=0;i<vecstr.size();i++)
    text_in+=vecstr[i];
	
	buildTree(text_in);
	
	return 0;
}