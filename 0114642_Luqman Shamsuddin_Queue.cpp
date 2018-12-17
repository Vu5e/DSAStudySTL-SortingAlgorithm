#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <queue>


using namespace std;

int main()
{
	srand(time(NULL));

	stack<int>	numberStack;
	queue<int>	numberQueue;
	queue<int>	numberQueueReverse;
		
	int randomSize = rand()%10 + 3;	
	
	cout << "===============" << endl;
	cout << "Top Order Queue" << endl;
	cout << "===============" << endl;
	for(int i = 0; i < randomSize; i++)
	{
		numberQueue.push(i);
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		cout<<numberQueue.front()<<endl;
		numberQueue.pop();
	}
	
	system("pause");
	system("cls");
	
	cout << "===================" << endl;
	cout << "Reverse Order Queue" << endl;
	cout << "===================" << endl;
	for(int i = 0; i < randomSize; i++)
	{
		numberQueue.push(i);
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		numberStack.push(numberQueue.front());
		numberQueue.pop();
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		numberQueueReverse.push(numberStack.top());
		numberStack.pop();
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		cout << numberQueueReverse.front() << endl;
		numberQueueReverse.pop();
	}
	
	system("pause");
	return 0;
}

// Name: Muhamad Luqman bin Shamsuddin
// ID: 0114642
