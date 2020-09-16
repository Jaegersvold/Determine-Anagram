// Joe Rensvold
// Section 2
// Project 1
// Due September 1st

/*
    This program will prompt the user for two lines of input.
    The letters from each line of input are then sorted into an array
    for each line of input. The arrays are then sorted and compared to
    determine if they contain the same elements. If the arrays contain
    the same elements, the user is told they have entered an anagram.
    If the arrays do not contain the same elements, the user
    is told they have not entered an anagram.
*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

  const int MAX = 61;

  char firstInput[MAX];
  char secondInput[MAX];


void inputLine(char input[])
{

    int index = 0;

    char letter;

    cin.get(letter);

    while (letter >= ' ')
    {
        if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            letter = tolower(letter);
            input[index] = letter;
            index++;
            cin.get(letter);
        }

        else
            cin.get(letter);

    }

    cout << endl;

}


void arraySort(char input[], int maxSize)
{
    int maxElement;
    int index;

    for (maxElement = maxSize - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (input[index] > input[index + 1])
            {
                swap(input[index], input[index + 1]);
            }
        }
    }
}



bool compareWords(char first[], char second[])
{
    int index;

    for(index = 0; index < MAX; index++)
    {
        if (first[index] != second[index])
            return false;
    }

    return true;
}

int main ()
{
    int index;

    cout << "Please enter two lines that may be anagrams." << endl;

    inputLine(firstInput);

    cout << "What is the next line?" << endl;
    inputLine(secondInput);

    arraySort(firstInput, MAX);
    arraySort(secondInput, MAX);

    bool isAnagrams =  compareWords(firstInput, secondInput);
    cout << "Are they anagrams?" << endl;

    if (isAnagrams)
        cout << "They are anagrams." << endl;
    else
        cout << "They are NOT anagrams." << endl;

    return 0;
}
