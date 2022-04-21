#pragma once

template <class T>
class SingleLinckedNode
{
public:
	T value;
	SingleLinckedNode* next;
	SingleLinckedNode(T value) 
	{ 
		this->value = value; 
		next = nullptr;
	}
	SingleLinckedNode() {};
};

