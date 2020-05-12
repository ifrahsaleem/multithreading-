#ifndef DynIntQueue_H
#define DynIntQueue_H

struct CustomerNode
{
	int customerId;
	CustomerNode* next;
	CustomerNode(int num, CustomerNode* ptr = NULL)
	{
		customerId = num;
		next = ptr;
	}
};

class DynIntQueue
{
private:
	// These track the front and rear of the queue.
	CustomerNode* front;
	CustomerNode* rear;
	int currentSize; // maxsize kalkacak
public:
	// Constructor.
	DynIntQueue();
	DynIntQueue(const HW8DynIntQueue& rhs);
	// Member functions.
	int getCurrentSize() const;
	DynIntQueue& operator=(const HW8DynIntQueue& rhs);
	void enqueue(int id);
	void dequeue(int& id);
	bool isEmpty() const;
	//Destructor
	~DynIntQueue();
};
#endif
