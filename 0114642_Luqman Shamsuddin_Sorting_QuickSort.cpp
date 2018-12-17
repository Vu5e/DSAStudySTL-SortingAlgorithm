#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<char> charList;

void RandomizeOrder()
{
	for (int i = 0; i < charList.size(); i++)
	{
		int randomIndex;
		
		do
		{
			randomIndex = rand() % charList.size();
		
		}while(randomIndex == i);
		
		int temp = charList[i];
		charList[i] = charList[randomIndex];
		charList[randomIndex] = temp;
	}
}

void QuickSortAscending(int left, int right)
{
	int i = left;
	int j = right;
	int temp;
	int pivot = charList [(left + right) / 2];
	
	while(i < j)
	{
		while(charList[i] < pivot)
			i++;
			
		while(charList[j] > pivot)
			j--;
		
		if (i <= j)
		{
			temp = charList[i];
			charList[i] = charList[j];
			charList[j] = temp;
			i ++;
			j --;
		}	
	}

	if (left <j)
		QuickSortAscending(left, j);
	if (i < right)
		QuickSortAscending(i, right);
	
}

void QuickSortDescending(int left, int right)
{
	int i = left;
	int j = right;
	int temp;
	int pivot = charList [(left + right) / 2];
	
	while(i < j)
	{
		while(charList[i] > pivot)
			i++;
			
		while(charList[j] < pivot)
			j--;
		
		if (i <= j)
		{
			temp = charList[i];
			charList[i] = charList[j];
			charList[j] = temp;
			i ++;
			j --;
		}	
	}

//! For recursive function (to fix)
	if (left <j)
		QuickSortDescending(left, j);
	if (i < right)
		QuickSortDescending(i, right);
}

void DoChoice(int choice)
{
	int left = 0, right = charList.size() - 1;
	if (choice == 1)
	{
		RandomizeOrder();
	}
	else if (choice == 2)
	{	
		QuickSortAscending(left, right);
	}
	else if (choice == 3)
	{
		QuickSortDescending(left, right);
	}
}

void DisplayVector()
{
	for (int i = 0; i < charList.size(); i++)
	{
		cout << "[" << i << "] : " << charList[i] << endl;
	}
}

int main()
{
	srand(time(NULL));
	
	int size = 10;
	
	for (int i = 0; i < size; i++)
	{
		charList.push_back(i + 65); 
	}
	
	int choice = -1;
	
	do
	{
		DisplayVector();
		cout << "==============================" << endl;
		cout << " 1. Randomize order"            << endl;
		cout << " 2. Sort in ascending order"    << endl;
		cout << " 3. Sort in descending order"   << endl;
		cout << "==============================" << endl;
		cout << "What would you like to do? : ";
		cin >> choice;
		
		if (cin.good())
		{
			DoChoice(choice);
		}
		else
		{
			cout << "Wrong input." << endl;
			system("pause");
		}
		
		cin.clear();
		cin.ignore(1000, '\n');
		system("cls");
		
	}while(choice != -1);

	return 0;
}

// Name: Muhamad Luqman bin Shamsuddin
// ID: 0114642
