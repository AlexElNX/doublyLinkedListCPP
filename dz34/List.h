#pragma once
#include <iostream>

struct Node
{
	Node* prev_;
	int data_;
	Node* next_;

	Node(int data) : prev_{ nullptr }, data_{ data }, next_{ nullptr } {}
};

template <class T>
class LinkedList
{
	Node* m_head;
	Node* m_tail;
public:
	LinkedList() : m_head{ nullptr }, m_tail{ nullptr } {}

	void addToHead(T data)
	{
		if (m_head == nullptr)
		{
			Node* new_node = new Node(data);
			m_head = m_tail = new_node;
			return;
		}
		Node* new_node = new Node(data);
		new_node->next_ = m_head;
		m_head->prev_ = new_node;
		m_head = new_node;
	}
	void addToTail(T data)
	{
		if (m_head == nullptr)
		{
			Node* new_node = new Node(data);
			m_head = m_tail = new_node;
			return;
		}
		Node* new_node = new Node(data);
		new_node->prev_ = m_tail;
		m_tail->next_ = new_node;;
		m_tail = new_node;
	}

	void deleteFromHead()
	{
		if (m_head == nullptr) return;
		Node* temp = m_head->next_; 
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
		Node* temp = m_tail->prev_;
		delete m_tail;
		m_tail = temp;
		if (m_tail == nullptr)
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
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
		Node* cur = m_head;
		while (cur)
		{
			std::cout << cur->data_ << " ";
			cur = cur->next_;
		}
	}

	int countElements()
	{
		Node* curCountElements = m_head;
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
		LinkedList list2;
		Node* cur = m_tail;

		if (cur == nullptr) return;
		Node* new_node = new Node(cur->data_);
		list2.m_head = list2.m_tail = new_node;

		cur = cur->prev_;

		int count{};
		int numberOfElements = countElements();
		while (cur)
		{

			if (count == numberOfElements - 1) break;
			Node* new_node = new Node(cur->data_);
			new_node->prev_ = list2.m_tail;
			list2.m_tail->next_ = new_node;
			list2.m_tail = new_node;

			cur = cur->prev_;
			++count;
		}
		deleteAll();
		m_head = list2.m_head;
		m_tail = list2.m_tail;

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
			Node* cur = m_head;
			for (int i{}; i < position - 2; ++i)
			{
				cur = cur->next_;
			}
			Node* new_node = new Node(data);
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
			Node* cur = m_head;
			for (int i{}; i < position - 2; ++i)
			{
				cur = cur->next_;
			}
			Node* temp = cur->next_;
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
		Node* cur = m_head;
		int count{};
		while (cur)
		{
			if (cur->data_ == data) return ++count;
			cur = cur->next_;
			++count;
		}
		return NULL;
		
	}

	int find(T data, T newData)
	{
		Node* cur = m_head;
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
};

