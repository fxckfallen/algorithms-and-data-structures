#include <iostream>
#include <stdexcept>

using namespace std;


template <typename T>
class List
{
public:
	List()
	{
		Size = 0;
		head = nullptr;
	}
	~List()
	{
		clear();
	}

	void pop_front()
	{
		Node<T>* temp = head;

		head = head->pNext;

		delete temp;

		Size--;
	}

	void clear() {
		while (Size) pop_front();
	}

	void push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;
			for (int i = 0; i < Size - 1; ++i) current = current->pNext;
			current->pNext = new Node<T>(data);
		}
		Size++;
	}

	int size() { return Size; }

	T& operator[](const int index) {
		if (index >= Size) throw invalid_argument("List index out of range");
		Node<T>* current = this->head;
		for (int i = 0; i < index; ++i) current = current->pNext;

		return current->data;
		//TODO: List index out of range
	}

	void push_front(T data) {
		head = new Node<T>(data, head);
		Size++;
	}

	void pop_back() {
		removeAt(Size - 1);
	}
	void insert(T data, int index) {
		if (index == 0) {
			push_front(data);
		}
		else {
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; ++i) previous = previous->pNext;

			previous->pNext = new Node<T>(data, previous->pNext);

			Size++;
		}
	}
	void removeAt(int index) {
		if (index == 0) {
			pop_front();
		}
		else {
			Node<T>* current = this->head;
			for (int i = 0; i < index - 1; ++i) current = current->pNext;

			Node<T>* toRemove = current->pNext;

			current->pNext = toRemove->pNext;

			delete toRemove;
			Size--;
		}
	}

private:


	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;

	Node<T>* head;
};


int main()
{
	List<int> test;

	test.push_back(1);
	test.push_back(14);
	test.push_back(21);
	test.push_back(1);

	for (int i = 0; i < test.size(); ++i) cout << test[i] << '\n';

	test.insert(2, 0);

	for (int i = 0; i < test.size(); ++i) cout << test[i] << '\n';
	return 0;
}