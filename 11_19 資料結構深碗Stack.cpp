#include<iostream>
using namespace std;

template<class T>
class Chain;

template<class T>
class ChainNode
{
	friend class Chain<T>;
public:
	ChainNode()
	{}
	ChainNode(const T& data)
	{
		this->data = data;
	}
	ChainNode(const T& data, ChainNode<T>* link)
	{
		this->data = data;
		this->link = link;
	}
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain
{
public:
	Chain() :first(nullptr) {}
	~Chain();
	bool IsEmpty() const 
	{ 
		return first == nullptr; 
	}
	
	void Push(const T& e) 
	{
		first = new ChainNode<T>(e, first); 
	}

	void Pop()
	{
		ChainNode<T>* temp = first;
		first = first->link;
		delete temp;
	}
	T& Top()
	{
		return first->data;
	}
	void Display()
	{
		for (ChainNode<T>* p = first; p != nullptr; p = p->link)
			cout << p->data << " ";
		cout << endl;
	}

private:
	ChainNode<T>* first;
};
template<class T>
Chain<T>::~Chain()
{
	while (first != nullptr)
	{
		ChainNode<T>* nextNode = first->link;
		delete first;
		first = nextNode;
	}
}


int main()
{
	Chain<int> s;
	int choice, x;

	do
	{
		cout << "\n=== Stack Menu ===\n";
		cout << "1. Push\n2. Pop\n3. Top\n4. IsEmpty\n5. Display\n0. Exit\n";
		cout << "Choice: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Stack: ";
			cin >> x;
			s.Push(x);
		}
		else if (choice == 2)
		{
			if (s.IsEmpty()) cout << "Stack is empty\n";
			else s.Pop();
		}
		else if (choice == 3)
		{
			if (s.IsEmpty()) cout << "Stack is empty\n";
			else cout << "Top = " << s.Top() << endl;
		}
		else if (choice == 4)
			cout << (s.IsEmpty() ? "Empty" : "Not empty") << endl;
		else if (choice == 5)
			s.Display();
	}
	while (choice != 0);

		return 0;
}