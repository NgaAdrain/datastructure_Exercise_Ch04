#pragma once
#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>

template <class T>
class Chain;

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *next;
};

template <class T>
class Chain {
public:
	Chain();//first setting
	void AddNode();
	void InsertNode(ChainNode<T> *obj,int index);
	void RemoveNode(int index);
	void ModifyNode(T& data, int index);
	void PrintNode(std::ostream &ostream);
private:
	ChainNode<T> *first;
	ChainNode<T> *last;
	int numOfNode;
};


////////////////////////////////////////
//====================================//
//Implements of Chain//
template <class T>
Chain<T>::Chain() {
	first = new ChainNode<T>();
	last = first;
	first->next = nullptr;
	numOfNode = 1;
}

template <class T>
void Chain<T>::AddNode() {
	last->next = new ChainNode<T>();
	last = last->next;
	numOfNode++;
	//Circular linked list//
	//last -> next = first;
}

template <class T>
void Chain<T>::InsertNode(ChainNode<T> *obj, int index) {
	ChainNode<T> *temp = first;
	if (index > numOfNode || index < -1) throw "index out of range! (last : -1, first : 0)";
	else if (index == -1||index == numOfNode) {
		last->next = obj;
		last = obj;
	}
	else{
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		obj->next = temp->next;
		temp->next = obj->next;
	}
	numOfNode++;
}

template <class T>
void Chain<T>::RemoveNode(int index) {
	ChainNode<T> *temp = first;
	ChainNode<T> *forDel;
	if (index > numOfNode || index < -1) throw "index out of range! (last : -1, first : 0)";
	else if (index == -1||index == numOfNode) {
		for (int i = 0; i < numOfNode - 1; i++) {
			temp = temp->next;
		}
		delete(temp->next);
		last = temp;
	}
	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		forDel = temp->next;
		temp->next = forDel->next;
		delete(forDel);
	}
	numOfNode--;
}

template <class T>
void Chain<T>::ModifyNode(T& data, int index) {
	ChainNode<T> *temp = first;
	if (index > numOfNode || index < -1) throw "index out of range! (last : -1, first : 0)";
	else if (index == -1 || index == numOfNode) {
		last->data = data;
	}
	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		temp->data = data;
	}
}

template <class T>
void Chain<T>::PrintNode(std::ostream &stream) {
	ChainNode<T> *temp = first;
	for (int index = 0; index < numOfNode; index++) {
		stream << index+1 << "번째 데이터 : " << temp->data << std::endl;
		temp = temp->next;
	}
}
////////////////////////////////////////
//====================================//
//Implements of ChainNode//


////////////////////////////////////////
#endif