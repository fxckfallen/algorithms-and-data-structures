#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node* prev, * next;

	Node(T data = T(), Node* prev = nullptr, Node* next = nullptr) {
		this->data = data;
		this->prev = prev;
		this->next = next;
	}
};

template <typename T>
class LinkedList {
public:
	Node<T>* head, * tail;
	
	int Size;

	LinkedList() {
		head = tail = nullptr;
		Size = 0;
	}

	~LinkedList() {
		clear();
	}

	int size() { return Size; }

	void push_front(T data) {
		Node<T>* ptr = new Node<T>(data);
		ptr->next = head;

		if (head != nullptr) head->prev = ptr;
		if (tail == nullptr) tail = ptr;

		head = ptr;
		Size++;
	}
	void push_back(T data) {
		Node<T>* ptr = new Node<T>(data);
		ptr->prev = tail;

		if (tail != nullptr) tail->next = ptr;
		if (head == nullptr) head = ptr;

		tail = ptr;
		Size++;
	}

	void pop_front() {
		if (head == nullptr) return;

		Node<T>* ptr = head->next;
		if (ptr != nullptr) ptr->prev = nullptr; else tail = nullptr;

		delete head;
		head = ptr;
		Size--;
	}

	void pop_back() {
		if (tail == nullptr) return;

		Node<T>* ptr = tail->prev;
		if (ptr != nullptr) ptr->prev = nullptr; else head = nullptr;

		delete tail;
		tail = ptr;
		Size--;
	}

	Node<T>* getAt(int index) {
		Node<T>* ptr = head;
		int n = 0;

		while (n != index) {
			if (ptr == nullptr) return ptr;
			ptr = ptr->next;
			n++;
		}

		return ptr;
	}
	T& operator[](const int index) {
		return getAt(index)->data;
	}

	void insert(int index, T data) {
		Node<T>* right = getAt(index);
		if (right == nullptr) {
			push_back(data);
			return;
		}
		Node<T>* left = right->prev;
		if (left == nullptr) {
			push_front(data);
			return;
		}

		Node<T>* ptr = new Node<T>(data);
		
		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;
		Size++;
	}

	void erase(int index) {
		Node<T>* ptr = getAt(index);
		if (ptr == nullptr) return;

		if (ptr->prev == nullptr) {
			pop_front();
			return;
		}

		if (ptr->next == nullptr) {
			pop_back();
			return;
		}

		Node<T>* left = ptr->prev;
		Node<T>* right = ptr->next;

		left->next = right;
		right->prev = left;

		delete ptr;
		Size--;
	}

	void clear() {
		while (Size) pop_front();
	}

};

int main()
{

	LinkedList<int> test;
	test.push_back(123);
	test.push_back(3);
	test.push_back(23);
	test.push_back(1);
	test.push_back(2);

	for (int i = 0; i < test.size(); ++i) cout << test[i] << '\n';

	return 0;
}