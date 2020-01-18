#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<vector>
#include<iostream>

namespace Poly {
	struct Node {
		int data;
		Node* next;
	};

	class Polynomial {

		friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);

		friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
	
	public:

		Polynomial();

		Polynomial(std::vector<int> polyVec);

		~Polynomial();

		Polynomial(const Polynomial& rhs);

		Polynomial& operator=(const Polynomial& rhs);

		Polynomial& operator+=(const Polynomial& rhs);

		int evaluate(int x);

	private:
		Node* headPtr;
		int degree;
	};

	int listLength(const Node* headPtr);

	void listDisplay(const Node* headPtr);

	void listInsertHead(int entry, Node*& headPtr);

	void listRemoveHead(Node*& headPtr);

	void listInsertAfter(int entry, Node* previousPtr);

	void listRemoveAfter(Node* previousPtr);

	Node* listFindLast(Node* headPtr);

	void listAppend(Node*& listOne, Node* listTwo);

	Node* listDuplicate(const Node* sourcePtr);

	void listClear(Node*& headPtr);

	Node* listSearch(int target, Node* headPtr);

	Node* listNodeAtIndex(int index, Node* headPtr);

	Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

	bool operator!=(const Polynomial rhs, const Polynomial lhs);

}
#endif
