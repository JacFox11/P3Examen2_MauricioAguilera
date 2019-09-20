#include<string.h>
#include <vector>
#include <bits/stdc++.h>
#include<iostream> 
#include<string> 
#include <fstream>
#include <stdlib.h>

using namespace std;

#ifndef Node_CPP
#define Node_CPP

class Node{
	private:
		string value;
		Node* next_node;
	public:
		
		Node(){
		}
		
		Node(string value){
			this->value=value;
		}
		
		string getValue(){
			return value;
		}
		
		void setValue(string value){
			this->value=value;
		}
		
		Node* getNext(){
			return next_node;
		}
		
		void setNext(Node* next_node){
			this->next_node=next_node;
		}
		
		void print(){
			cout<<value;
		}
};

#endif
