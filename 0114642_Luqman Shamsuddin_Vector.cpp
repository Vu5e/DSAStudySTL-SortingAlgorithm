#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<char> charVector;

void DisplayVector()
{
	for (int i = 0; i < charVector.size(); i++)
	{
		cout << "[" << i << "] : " << charVector[i] << endl;
	}
}

//to randomize order (best known method)
void RandomizeOrder()
{
	for(int i =0; i < charVector.size(); i++)
	{
		int randomIndex;
		do
		{
			randomIndex = rand()%charVector.size();
		}while(randomIndex == i);
		
		char temp = charVector[i];
		charVector[i] = charVector[randomIndex];
		charVector[randomIndex] = temp;
	}
}

// push to the back word
void PushToBackVector(char character)
{	
	charVector.push_back(character); 
}

//push to the front word
void PushToFrontVector(char character)
{
	charVector.insert(charVector.begin(), character);
}

//specific index (use insert)
void PushToSpecificIndex(char character, int index)
{
	
	//charVector.begin() + index
	//(character)
	if (charVector.size() >= index)
	{
		charVector.insert(charVector.begin() + index, character); 
	}
	
	else
	{
		cout << "There is unused index." << endl;
		system("pause");
	}
}

void PopFromBackVector()
{
	//use pop, + back
	if (!charVector.empty())
	{
		charVector.pop_back();
	}
	
	else
	{
		cout << endl << "Vector is already empty." << endl;
		system("pause");
	}
}

void PopFromFrontVector()
{
	//same as popfroback
	if (!charVector.empty())
	{
		charVector.erase(charVector.begin()); 
	}
	
	else
	{
		cout << endl<< "Vector is already empty." << endl;
		system("pause");
	}
}

void PopFromSpecificIndex(int index)
{	
	//use charVector.begin() + index
	if (charVector.size() > index)
	{
		charVector.erase(charVector.begin() + index);
	}
	
	else
	{
		cout << endl<< "Vector does not contain that index." << endl;
		system("pause");
	}
}

void SwapAtSpecificIndex(int index1, int index2)
{	
	//use swap + .begin and specific index
	if (charVector.size() > index1 && charVector.size() > index2)
	{
		if (index1 >= index2)
		{
			cout << "First index needs to smaller and not equal to second index." << endl;
			system("pause");
		}
		
		else
		{
		//	int a = 1;
		//	int b = 2;
		//	int temp = a;
		//	a = b;
		//	b = temp;
		
			char temp1 = charVector[index1];
			char temp2 = charVector[index2];
			
			charVector.erase(charVector.begin() + index1);
			charVector.insert(charVector.begin() + index1, temp2);
			charVector.erase(charVector.begin() + index2);
			charVector.insert(charVector.begin() + index2, temp1);
		}
	}
	
	else
	{
		cout << "Both of the inputed index is not available inside the vector." << endl;
		system("pause");
	}
}

void DeleteAllVectors()
{
	//use clear
	if (!charVector.empty())
	{
		charVector.clear(); 
	}
	
	else
	{	
		cout << endl;
		cout << "Vector is already empty." << endl;
		system("pause");
	}
}

void ReverseOrder()
{
	//! 1. insert last one to i
	//! 2. pop the last one
	//! 4. loop it
	//! 5. store when i = charVector.size
	
	
	for(int i = 0; i < charVector.size(); i++)
	{
		PushToSpecificIndex(charVector[charVector.size() - 1], i);
		charVector.pop_back();
	}
	
}

void DoChoice(int choice)
{
	if(choice == 1)
	{
		RandomizeOrder();
	}
	
	else if(choice == 2)
	{
		char character;
		cout << "Please input a character : ";
		cin >> character;
		PushToBackVector(character);
	}
	
	else if(choice == 3)
	{
		char character;
		cout << "Please input a character : ";
		cin >> character;
		PushToFrontVector(character);
	}

	else if(choice == 4)
	{
		char character;
		cout << "Please input a character : ";
		cin >> character;
		
		int index;
		cout << "Please input desired index : ";
		cin >> index;
		PushToSpecificIndex(character, index);
	}
	
	else if(choice == 5)
	{
		PopFromBackVector();
	}
	
	else if(choice == 6)
	{
		PopFromFrontVector();
	}
	
	else if(choice == 7)
	{
		int index;
		cout << "Please input desired index : ";
		cin >> index;
		PopFromSpecificIndex(index); 
	}
	
	else if(choice == 8)
	{
		int index1, index2;
		cout << "Please input first index : ";
		cin >> index1;
		cout << "Please input second index : ";
		cin >> index2;
		SwapAtSpecificIndex(index1, index2);
	}
	
	else if(choice == 9) 
	{
		DeleteAllVectors();
	}
	
	else if(choice == 10)
	{
		ReverseOrder();
	}
	
	else
	{
		system("cls");
		cout << "\tPlease choose a valid program ..." << endl;
		cout << endl;
		system("pause");
	}
}

int main()
{
	srand(time(NULL));
	
	int randomSize = rand() % 7 + 3; // 0 -> 9
	
	for (int i = 0; i < randomSize; i++)
	{
		charVector.push_back(i + 65); 
	}
	
	int choice = -1;
	
	do
	{
		DisplayVector();
		cout << "========================================"  << endl;
		cout << "  1. Randomize Order"                      << endl;
		cout << "  2. Add character to the back"            << endl;
		cout << "  3. Add character to the front"           << endl;
		cout << "  4. Add character at specific index"      << endl;
		cout << "  5. Remove character at the back"         << endl;
		cout << "  6. Remove character at the front"        << endl;
		cout << "  7. Remove character at specific index"   << endl;
		cout << "  8. Swap character at specific indexes"   << endl;
		cout << "  9. Delete all characters"                << endl;
		cout << "  10. Reverse Order"                        << endl;
		cout << " -1. BREXIT"                                 << endl;
		cout << "======================================="   << endl;
		cout << "What would you like to do? : " ; 
		cin >> choice;
		
		if(cin.good())
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
