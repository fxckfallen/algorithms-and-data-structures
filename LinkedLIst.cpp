#include <iostream>
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
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		Size++;
	}

	int size() { return Size; }

	T& operator[](const int index) {
		Node<T>* current = this->head;

		for (int i = 0; i < index; ++i) current = current->pNext;

		return current->data;
		//TODO: List index out of range
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
	return 0;
}