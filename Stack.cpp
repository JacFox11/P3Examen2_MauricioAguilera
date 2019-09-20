#include "Node.cpp"

#ifndef Stack_CPP
#define Stack_CPP

class Stack{
	private:
		Node* head;
	public:
		
		Stack(){
		}
		
		Stack(Node* head){
			this->head=head;
		}
		
		void Push(string value){
			Node* temp=new Node(value);
			temp->setNext(head);
			head=temp;
		}
		
		Node* Pop(){
			Node* temp=head;
			head=head->getNext();
			return temp;
		}
		
		Node* Top(){
			return head;
		}
		
		bool isEmpty(){
			if (head->getNext()==NULL){
				return true;
			}else{
				return false;
			}
		}
};

#endif
