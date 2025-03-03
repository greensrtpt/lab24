#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

void List::remove(int idx) {
    if (root == NULL || idx < 0) return; // กรณีที่ลิสต์ว่างหรือดัชนีไม่ถูกต้อง

    Node *current = root;
    if (idx == 0) { // กรณีลบโหนดตัวแรก
        root = root->next;
        delete current;
        return;
    }

    Node *prev = nullptr;
    for (int i = 0; i < idx; i++) {
        prev = current;
        current = current->next;
        if (current == NULL) return; // ดัชนีเกินขนาดของลิสต์
    }

    prev->next = current->next;
    delete current;
}
