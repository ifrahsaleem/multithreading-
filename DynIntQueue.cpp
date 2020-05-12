#include <iostream>
#include "DynIntQueue.h"
using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
DynIntQueue::DynIntQueue()
{
	front = NULL;
	rear = NULL;
	currentSize = 0;
}



//************************************************
// Copy Constructor.                             *
//************************************************
DynIntQueue::DynIntQueue(const DynIntQueue& rhs)
{
	front = NULL;
	rear = NULL;
	currentSize = 0;

	if(!rhs.isEmpty())
	{
		currentSize = 0;
		CustomerNode* tmp = rhs.front;
		while (tmp != NULL)
		{
			enqueue(tmp->customerId);
			tmp = tmp->next;
		}
	}
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
void DynIntQueue::enqueue(int num)
{
	 if (isEmpty())   //if the queue is empty
	{	//make it the first element
		front = new CustomerNode(num);
		rear = front;
		currentSize++;

	}
	else  //if the queue is not empty
	{	//add it after rear
		rear->next = new CustomerNode(num);
		rear = rear->next;
		currentSize++;

	}

}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
void DynIntQueue::dequeue(int & num)
{
	CustomerNode* temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else //if the queue is not empty
	{	//return front's value, advance front and delete old front
		num = front->customerId;
		temp = front;
		front = front->next;
		delete temp;
		currentSize--;
	}
}

//*********************************************
// Function getCurrentSize returns current    *
// size of the queue.						  *
//*********************************************
int DynIntQueue::getCurrentSize() const
{
	return currentSize;
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
bool DynIntQueue::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}

//*********************************************
// Assignment Operator						  *
//*********************************************
DynIntQueue& DynIntQueue::operator=(const DynIntQueue& rhs)
{
	if (this != &rhs) //self assignment check
	{

		int value;   // Dummy variable for dequeue
		while (!isEmpty())
			dequeue(value); //delete all elements
	
		front = NULL;
		rear = NULL;
		currentSize = 0;
		
		CustomerNode* tmp = rhs.front;
		while (tmp != NULL)
		{
				enqueue(tmp->customerId);
				tmp = tmp->next;
		}

	}
	return *this;
}
//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
DynIntQueue::~DynIntQueue()
{
	int value;   // Dummy variable for dequeue

	while (!isEmpty())
		dequeue(value); //delete all elements
}

