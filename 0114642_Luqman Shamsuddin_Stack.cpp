#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>

using namespace std;

int main()
{
	srand(time(NULL));

	stack<int>	numberStack;
	stack<int>  numberStackReverse;
	
	int randomSize = rand()%10 + 3; 
	
	cout << "===============" << endl;
	cout << "Top Order Stack" << endl;
	cout << "===============" << endl;
	for(int i = 0; i < randomSize; i++)
	{
		numberStack.push(i);
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		cout << numberStack.top() << endl;
		numberStack.pop();
	}
	
	system("pause");
	system("cls");
	
	cout << "===================" << endl;
	cout << "Reverse Order Stack" << endl;
	cout << "===================" << endl;
	for(int i = 0; i < randomSize; i++)
	{
		numberStack.push(i);
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		numberStackReverse.push(i);
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		numberStackReverse.push(numberStack.top());
		numberStack.pop();
	}
	
	for(int i = 0; i < randomSize; i++)
	{
		cout << numberStackReverse.top() << endl;
		numberStackReverse.pop();
	}
	
	system("pause");	
	return 0;
}

// Name: Muhamad Luqman bin Shamsuddin
// ID: 0114642
