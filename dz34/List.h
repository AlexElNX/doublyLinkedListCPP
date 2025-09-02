#pragma once
#include <iostream>

template <typename T>
struct Node
{
	Node* prev_;
	T data_;
	Node* next_;

	Node(int data) : prev_{ nullptr }, data_{ data }, next_{ nullptr } {}
};

template <class T>
class LinkedList
{
	Node<T>* m_head;
	Node<T>* m_tail;
public:
	LinkedList() : m_head{ nullptr }, m_tail{ nullptr } {}

	void addToHead(T data)
	{
		Node<T>* new_node = new Node<T>(data);
		if (m_head == nullptr)
		{
			m_head = m_tail = new_node;
			return;
		}

		new_node->next_ = m_head;
		m_head->prev_ = new_node;
		m_head = new_node;
	}
	void addToTail(T data)
	{
		Node<T>* new_node = new Node<T>(data);
		if (m_head == nullptr)
		{
			m_head = m_tail = new_node;
			return;
		}
		new_node->prev_ = m_tail;
		m_tail->next_ = new_node;;
		m_tail = new_node;
	}

	void deleteFromHead()
	{
		if (m_head == nullptr) return;
		Node<T>* temp = m_head->next_;
		delete m_head;
		m_head = temp;
	}

	void deleteFromTail()
	{
		if (m_head == nullptr) return;
		if (m_head == m_tail)
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* temp = m_tail->prev_;
		delete m_tail;
		m_tail == nullptr;
		m_tail = temp;
		m_tail->next_ = nullptr;
	}

	void deleteAll()
	{
		while (m_head)
		{
			deleteFromHead();
		}
	}

	void show() const
	{
		Node<T>* cur = m_head;
		while (cur)
		{
			std::cout << cur->data_ << " ";
			cur = cur->next_;
		}
	}

	int countElements()
	{
		Node<T>* curCountElements = m_head;
		int numberOfElements{};
		while (curCountElements)
		{
			++numberOfElements;
			curCountElements = curCountElements->next_;
		}
		return numberOfElements;
	}


	void reverse()
	{
		LinkedList<T>* list2 = new LinkedList<T>();
		Node<T>* cur = m_tail;

		if (cur == nullptr) return;
		Node<T>* new_node = new Node<T>(cur->data_);
		list2->m_head = list2->m_tail = new_node;

		cur = cur->prev_;
		if (m_head->prev_) m_head->prev_ = nullptr;

		while (cur)
		{
			if (cur->prev_ == nullptr) break;
			Node<T>* new_node = new Node<T>(cur->data_);
			new_node->prev_ = list2->m_tail;
			list2->m_tail->next_ = new_node;
			list2->m_tail = new_node;

			cur = cur->prev_;
		}

		deleteAll();
		m_head = list2->m_head;
		m_tail = list2->m_tail;
		list2->m_head = nullptr;
		list2->m_tail = nullptr;
		delete list2;

	}


	void insert(int position, T data)
	{
		int numberOfElements = countElements();
		if (position == 1)
		{
			addToHead(data);
			return;
		}
		else if (position == numberOfElements)
		{
			addToTail(data);
		}
		else if (position > 1 && position < numberOfElements)
		{
			Node<T>* cur = m_head;
			for (int i{}; i < position - 2; ++i)
			{
				cur = cur->next_;
			}
			Node<T>* new_node = new Node<T>(data);
			new_node->next_ = cur->next_;
			new_node->prev_ = cur;
			new_node->next_->prev_ = new_node;
			cur->next_ = new_node;
		}
	}


	void remove(int position)
	{
		int numberOfElements = countElements();
		if (position == 1)
		{
			deleteFromHead();
			return;
		}
		else if (position == numberOfElements)
		{
			deleteFromTail();
		}
		else if (position > 1 && position < numberOfElements)
		{
			Node<T>* cur = m_head;
			for (int i{}; i < position - 2; ++i)
			{
				cur = cur->next_;
			}
			Node<T>* temp = cur->next_;
			cur->next_ = temp->next_;
			temp->next_->prev_ = cur;
			delete temp;
		}
		else
		{
			std::cout << "Error!\n";
			return;
		}
	}


	int find(T data)
	{
		Node<T>* cur = m_head;
		int count = 1;
		while (cur)
		{
			if (cur->data_ == data) return count;
			cur = cur->next_;
			++count;
		}
		return NULL;

	}

	int findAndReplace(T data, T newData)
	{
		Node<T>* cur = m_head;
		int count{};
		while (cur)
		{
			if (cur->data_ == data)
			{
				cur->data_ = newData;
				++count;
			}
			cur = cur->next_;

		}
		if (count > 0) return count;
		else return -1;

	}

	~LinkedList()
	{
		Node<T>* cur = m_head;
		while (cur)
		{
			Node<T>* next = cur->next_;
			delete cur;
			cur = next;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}


};

