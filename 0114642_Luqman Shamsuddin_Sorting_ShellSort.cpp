#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

vector<char> charList;

void RandomizeOrder()
{
	for(int i =0; i < charList.size(); i++)
	{
		int randomIndex;
		do
		{
			randomIndex = rand()%charList.size();
		}while(randomIndex == i);
		
		char temp = charList[i];
		charList[i] = charList[randomIndex];
		charList[randomIndex] = temp;
	}
}

void ShellSortAscending()
{
	int d = charList.size();
	do {
		d = (d + 1)/2;
		for (int i =0; i < (charList.size() - d); i++)
		{
			if (charList[i + d] < charList[i])
			{
				int temp = charList[i+d];
				charList[i + d] = charList[i];
				charList[i] = temp;
			}
		}
	} while(d > 1);
}

void ShellSortDescending()
{
	int d = charList.size();
	do {
		d = (d + 1)/2;
		for (int i =0; i < (charList.size() - d); i++)
		{
			if (charList[i + d] > charList[i])
			{
				int temp = charList[i+d];
				charList[i + d] = charList[i];
				charList[i] = temp;
			}
		}
	} while(d > 1);
}

void DoChoice(int choice)
{
	if(choice == 1)
	{
		RandomizeOrder();
	}
	else if(choice == 2)
	{
		ShellSortAscending();
	}
	else if(choice == 3)
	{
		ShellSortDescending();
	}
}

void DisplayVector()
{
	for(int i =0; i < charList.size(); i++)
	{
		cout << "[" << i << "] : " << charList[i] <<endl;
	}
}

int main()
{
	srand(time(NULL));
	
	int size = 10;
	
	for(int i = 0; i < size; i++)
	{
		charList.push_back(i + 65);
	}
	
	int choice = -1;
	
	do
	{
		DisplayVector();
		
		cout << "============================" << endl;
		cout << "1. Randomize Order" << endl;
		cout << "2. Sort in ascending order" << endl;
		cout << "3. Sort in descending order" << endl;
		cout << "-1 Exit" << endl;
		cout << "============================" << endl;
		
		cout << "What would you like to do? : ";
		cin >> choice;
		if(cin.good())
		{
			DoChoice(choice);
		}
		else
		{
			cout << "WRONG INPUT!!!!" << endl;
			system("PAUSE");
		}
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
	}while(choice != -1);
	
	system("PAUSE");
	return 0;
}

// Name: Muhamad Luqman bin Shamsuddin
// ID: 0114642
