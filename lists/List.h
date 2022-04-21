#pragma once

template <class T>
class List abstract
{
protected:
	//virtual bool Remove(Node<T> *prev, Node<T> *curr, Node <T>*next) = 0;
public:
	virtual int GetCount() = 0;
	virtual bool Remove(T value_to_remove) = 0;
	virtual bool RemoveAt(int index) = 0;
	virtual T GetElementAt(int indx) = 0;
	virtual void SetElementAt(int indx, T value) = 0;
	virtual void Add(T value) = 0;
};

