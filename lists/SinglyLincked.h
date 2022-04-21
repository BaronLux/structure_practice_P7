#pragma once
#include "List.h"
#include "SingleLinckedNode.h"
#include <iostream>
using namespace std;
template <class T>
class SinglyLincked :
	public List<T>
{
	SingleLinckedNode<T>* first, *last;
	int element_count;
	virtual bool Remove(SingleLinckedNode<T>* prev, SingleLinckedNode<T>* curr, SingleLinckedNode<T>* next)
	{
		if (prev == nullptr && next == nullptr)
		{
			first = nullptr;
			last = nullptr;
		}
		else if (prev == nullptr)
		{
			first = next;
		}
		else if (next == nullptr)
		{
			last = prev;
			prev->next = nullptr;
		}
		else
		{
			prev->next = next;
		}
		element_count--;
		return 1;
	}
public:
	int GetCount()
	{
		return element_count;
	}
	virtual T GetElementAt(int indx)
	{
		int i = 0;
		for (SingleLinckedNode<T>
			*prev = nullptr,
			*curr = first,
			*next = curr->next;
			i < element_count;
			prev = curr,
			curr = next,
			next = curr->next)
		{
			if (i == indx)
			{
				return curr->value;
			}
			i++;
		}
		return NULL;
	}
	virtual void SetElementAt(int indx, T value)
	{
		int i = 0;
		for (SingleLinckedNode<T>
			* prev = nullptr,
			*curr = first,
			*next = curr->next;
			i < element_count;
			prev = curr,
			curr = next,
			next = curr->next)
		{
			if (i == indx)
			{
				curr->value = value;
			}
			i++;
		}
	}
	bool Remove(T value)
	{
		for (SingleLinckedNode<T>
			*prev = nullptr,
			*curr = first,
			*next = curr->next;
			true;
			prev = curr,
			curr = next,
			next = curr->next)
		{
			if (curr->value == value)
			{
				return Remove(prev, curr, next);
			}
			if (next == nullptr)
			{
				break;
			}
		}
		return false;
	}
	bool RemoveAt(int index) { return 0; };
	void Add(T value)
	{
		auto added = new SingleLinckedNode<T>(value);
		if (first == nullptr && last == nullptr)
		{
			first = added;
			first->next = last;
		}
		else if (last == nullptr)
		{
			last = added;
			first->next = last;
		}
		else
		{
			last->next = added;
			last = last->next;
		}
		element_count++;
	}
	void Print()
	{
		int i = 0;
		cout << "count=" << GetCount() << endl;
		if (element_count > 0)
		{
			for (SingleLinckedNode<T>
				* prev = nullptr,
				*curr = first,
				*next = curr->next;
				true;
				prev = curr,
				curr = next,
				next = curr->next)
			{
				cout << curr->value << '\t';
				i++;
				if (i == element_count)
				{
					break;
				}
			}
			cout << endl;
		}
	}
};


