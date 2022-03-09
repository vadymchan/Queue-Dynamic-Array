#pragma once
#include <iostream>
template<typename T>
class Queue
{
public:
	Queue(int SIZE);
	~Queue();

	void push(T value); //maybe I'll chage it to T
	T front();
	T back();
	T pop();
	int count();
	int capacity();
	bool empty();
	bool full();
	void move(); 
	T operator[](const int index);


private:
	T* arr;
	int SIZE;
	int head, rear;
};

template<typename T>
Queue<T>::Queue(const int SIZE)
{
	this->SIZE = SIZE;
	arr = new T[SIZE];
	head = rear = -1;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] arr;
}

template<typename T>
void Queue<T>::push(T value)
{
	if (full())
	{
		if (head == 0)
		{
			std::cout << "Queue is FULL" << std::endl;
			return;
		}
		move();
		push(value);
		return; 
	}
	else if (empty())
	{
		head = rear = 0;
	}
	else
	{
		rear++;
	}
	arr[rear] = value;

}

template<typename T>
T Queue<T>::front()
{
	return arr[head];
}

template<typename T>
T Queue<T>::back()
{
	return arr[rear];
}

template<typename T>
T Queue<T>::pop()
{
	T popped_elem = arr[head];
	head++;
	return popped_elem;
}

template<typename T>
int Queue<T>::count()
{
	return rear - head + 1;
}

template<typename T>
int Queue<T>::capacity()
{
	return SIZE;
}

template<typename T>
bool Queue<T>::full()
{
	return rear == SIZE - 1;
}

template<typename T>
bool Queue<T>::empty()
{
	return head == -1 && rear == -1;
}

template<typename T>
void Queue<T>::move()
{
	T* temp = new T[SIZE];
	for (int i = head, j = 0; i <= rear; ++i, ++j)
	{
		temp[j] = arr[i];
	}
	rear = rear - head;
	head = 0;
	delete[] arr;
	arr = temp;
}

template<typename T>
T Queue<T>::operator[](const int index)
{
	if (index >= 0 && index < SIZE)
		return arr[index];
	std::cout << "Index is negative or larger than a size of queue" << std::endl;
}

