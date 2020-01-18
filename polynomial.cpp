#include "polynomial.h"
#include <iostream>

using namespace std;

namespace Poly {

	ostream& operator<<(ostream& os, const Polynomial& rhs) {
		Node* curr = rhs.headPtr;
		while (curr != NULL) {
			os << "->" << curr->data << ' ';
			curr = curr->next;
		}
		return os;
	}

	bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		if (lhs.degree != rhs.degree) {
			return false;
		}
		Node* curr1 = lhs.headPtr;
		Node* curr2 = rhs.headPtr;
		while (curr1 != NULL) {
			if (curr1->data != curr2->data) {
				return false;
			}
		}
		return true;
	}
	
	Polynomial::Polynomial() : headPtr(NULL), degree(0) {}

	Polynomial::Polynomial(vector<int> polyVec) {
		Node* prev = new Node;
		prev->data = polyVec[0];
		prev->next = NULL;
		for (size_t i = 1; i < polyVec.size(); ++i) {
			Node* curr = new Node;
			curr->data = polyVec[i];
			curr->next = prev;
			prev = curr;
			headPtr = curr;
			degree += 1;
		}
	}

	Polynomial::~Polynomial() {
		Node* curr = headPtr;
		while (curr != NULL) {
			delete curr;
		}
	}

	Polynomial::Polynomial(const Polynomial& rhs) {
		headPtr = listDuplicate(rhs.headPtr);
		degree = rhs.degree;
	}

	Polynomial& Polynomial::operator=(const Polynomial& rhs) {
		if (*this != rhs) {
			Node* curr = headPtr;
			while (curr != NULL) {
				delete curr;
				curr = curr->next;
			}
			headPtr = listDuplicate(rhs.headPtr);
			degree = rhs.degree;
		}
		return *this;
	}

	Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
		Node* curr1 = headPtr;
		Node* curr2 = rhs.headPtr;
		while (curr2 != NULL) {
			curr1->data += curr2->data;
			if (curr1 == NULL) {
				curr1 = curr2;
				curr1->next = NULL;
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		return *this;
	}

	int Polynomial::evaluate(int x) {
		Node* currNode = headPtr;
		int currPow = 0;
		int result = 0;
		while (currNode != NULL) {
			result += currNode->data * currPow;
			currNode = currNode->next;
			currPow += 1;
		}
		return result;
	}

	Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
		Polynomial* result = new Polynomial(lhs);
		*result += rhs;
		return *result;
	}

	bool operator!=(const Polynomial rhs, const Polynomial lhs) {
		return !(rhs == lhs);
	}

	int listLength(const Node* headPtr) {
		int length = 0;
		const Node* p = headPtr;

		while (p != NULL) {
			length++;
			p = p->next;
		}
		return length;
	}

	int listLengthFor(const Node* headPtr) {
		int length = 0;
		for (const Node* p = headPtr; p != NULL; p = p->next)
			length++;
		return length;
	}

		void listDisplay(const Node* headPtr) {
		const Node* p = headPtr;
			while (p != NULL) {
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}

	void listInsertHead(int entry, Node*& headPtr) {
		Node* temp = new Node;
		temp->data = entry;
		temp->next = headPtr;
		headPtr = temp;
	}

	void listRemoveHead(Node*& headPtr) {
		if (headPtr != NULL) {
			Node* second = headPtr->next;
			delete headPtr;
			headPtr = second;
		}
	}

	void listInsertAfter(int entry, Node* previousPtr) {
		Node* temp = new Node;
		temp->data = entry;
		temp->next = previousPtr->next;
		previousPtr->next = temp;
	}

	void listRemoveAfter(Node* previousPtr) {
		Node* removePtr = previousPtr->next;
		previousPtr->next = removePtr->next;
		delete removePtr;
	}

	Node* listFindLast(Node* headPtr) {
		Node* p = headPtr;
		if (p != NULL) {
						while (p->next != NULL)
				p = p->next;
		}
		return p;
	}

	void listAppend(Node*& listOne, Node* listTwo) {
		if (listOne == NULL)
			listOne = listTwo;
		else {
			Node* p = listFindLast(listOne);
			p->next = listTwo;
		}
	}

	Node* listDuplicate(const Node* sourcePtr) {
		if (sourcePtr == NULL)
			return NULL;
		Node* newHead = new Node;
		newHead->data = sourcePtr->data;
		newHead->next = NULL;

		Node* last = newHead;
		const Node* p = sourcePtr->next;
		while (p != NULL) {
			listInsertAfter(p->data, last);
			last = last->next;
			// 
			p = p->next;
		}
		return newHead;
	}

	void listClear(Node*& headPtr) {
		Node *p = headPtr;
		headPtr = NULL;
		while (p != NULL) {
			Node *link = p->next;
			delete p;
			p = link;
		}
	}


	Node* listSearch(int target, Node* headPtr) {
		Node* p = headPtr;
		while (p != NULL && p->data != target)
			p = p->next;
		return p;
	}

	Node* listNodeAtIndex(int index, Node* headPtr) {
		int count = 0;
		Node* p = headPtr;
		while (count < index && p != NULL) {
			count++;
			p = p->next;
		}
		return p;
	}

}