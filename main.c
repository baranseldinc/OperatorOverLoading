#include <iostream>
using namespace std;
class Node{
	public:
		int value;
		Node *next;
};
class List {
	public:
		Node *bas;
		Node *son;
		int size;
		List() {
			this->bas = 0;
			this->son = 0;
			this->size = 0;
			 
		}
		void add(int value) {
			Node *node = new Node();
			node->value = value;
			node->next = 0;
			if(this->bas == 0) {
				bas = node;
				son = node;
				size++;
				return;
			}
			son->next = node;
			son = node;
			size++;
			return;
		}
		void printList() {
			if(this->bas == 0) {
				cout << "Liste icerisi bos..." << endl;
				return;
			}
			Node *current;
			current = bas;
			while(current != 0) {
				cout << current->value << ",";
				current = current->next;
			}cout<<endl;
		}
		int& operator[] (const int index) {
			if(index<0 || index>=size) {
				cout << "Index degeri liste sinirlari disinda kontrol ediniz..."<< endl;
			}
			int temp = index;
			Node *current = this->bas;
			while(temp--) {
				current = current->next;
			}
			return current->value;
		}
};
int main(int argc, char** argv) {
	List *liste = new List();
	liste->add(5);
	liste->add(2);
	liste->add(-6);
	liste->add(3);
	liste->printList();
	cout << liste->operator[](2)<< endl;
	return 0;
}
