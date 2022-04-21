template <class T>
class DoubleLinckedNode
{
public:
	T value;
	DoubleLinckedNode* next, *prev;
	DoubleLinckedNode(T value)
	{
		this->value = value;
		next = nullptr;
	}
	DoubleLinckedNode() {};
};

