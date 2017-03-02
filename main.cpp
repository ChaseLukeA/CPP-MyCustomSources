#include <iostream>
#include <sstream>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;


/* forward declarations of helper functions */
template <typename T>
string toString(T number);

string ordinalSuffix(int number);


int main()
{
    cout << "----------------------------------------------------" << endl;
    cout << "  LinkedList testing:" << endl;
    cout << "----------------------------------------------------" << endl << endl;

    LinkedList<string> romanNumerals;

    string i = "First";
    string ii = "Second";
    string iii = "Third";
    string iv = "Fourth";
    string v = "Fifth";
    string vi = "Sixth";
    string vii = "Seventh";
    string viii = "Eighth";
    string ix = "Ninth";
    string x = "Tenth";
    string n = "Nth";

    romanNumerals.addLast(ii);
    romanNumerals.addLast(iii);
    romanNumerals.addLast(v);
    romanNumerals.addBefore(iv, 2);
    romanNumerals.addFirst(i);
    romanNumerals.addAfter(vi, 8);
    romanNumerals.addLast(ix);
    romanNumerals.addAfter(vii, 5);
    romanNumerals.addBefore(viii, 7);
    romanNumerals.addFirst(n);
    romanNumerals.addLast(n);
    romanNumerals.removeAt(0);
    romanNumerals.addAfter(x, 10);
    romanNumerals.removeAt(9);
    romanNumerals.removeAt(10);

    cout << "Roman Numerals (" << romanNumerals.getSize() << " elements):" << endl;
    romanNumerals.print();

    LinkedList<string> romanNumeralsCopy(romanNumerals);

    delete &romanNumerals;

    cout << endl << "Roman Numerals (" << romanNumerals.getSize() << " elements):" << endl;
    romanNumerals.print();

    LinkedList<string> romanNumeralsEmptyCopy(romanNumerals);

    cout << endl << "Roman Numerals Empty Copy (" << romanNumeralsEmptyCopy.getSize() << " elements):" << endl;
    romanNumeralsEmptyCopy.print();

    cout << endl << "Roman Numerals Copy (" << romanNumeralsCopy.getSize() << " elements):" << endl;
    romanNumeralsCopy.print();

    delete &romanNumeralsEmptyCopy;

    cout << endl << endl << "Printing Roman Numerals Copy using Iterator..." << endl;

    for (LinkedList<string>::Iterator itr = romanNumeralsCopy.begin();
    itr != romanNumeralsCopy.end(); itr++)
    {
        cout << (*itr) << endl;
    }

    int choice = 0;
    cout << endl << "Select a number to see what value it contains: ";
    cin >> choice;

    LinkedList<string>::Iterator itr = romanNumeralsCopy.begin();
    int count = 1;
    while (count < choice)
    {
        count++;
        itr++;
    }

    cout << endl << "Number " << choice << " is \"" << (*itr) << "\"" << endl << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "  Stack and Queue testing:" << endl;
    cout << "----------------------------------------------------" << endl << endl;

    Queue<int> numbersQueue;
    Stack<int> numbersStack;
    int numbersTotal = 0;
    int number;

    while (number != -1)
    {
        cout << "Enter the " << ordinalSuffix(++numbersTotal) << " number for the Stack and Queue: ";
        cin >> number;
        if (number != -1)
        {
            numbersQueue.enQueue(number);
            numbersStack.push(number);
        }
    }

    // saving the final size because otherwise it decreases on .deQueue() and won't release all queued items
    numbersTotal = numbersQueue.size();

    cout << endl << "Releasing " << numbersTotal << " numbers from the Queue..." << endl << endl;

    for (int i = 0; i < numbersTotal; i++)
    {
        cout << "Released '" << numbersQueue.front() << "' from the Queue!" << endl;
        numbersQueue.deQueue();
    }

    cout << endl << "Releasing " << numbersTotal << " numbers from the Stack..." << endl << endl;

    for (int i = 0; i < numbersTotal; i++)
    {
        cout << "Released '" << numbersStack.top() << "' from the Stack!" << endl;
        numbersStack.pop();
    }

    return 0;
}

// I wanted a simple way to convert any number to a string
template <typename T>
string toString(T number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
}

// I previously came up with this formula in Objective-C, reusing it here in C++
string ordinalSuffix(int number)
{
    switch (number%100)
    {
    case 1:
        return toString(number) + "st";
    case 2:
        return toString(number) + "nd";
    case 3:
        return toString(number) + "rd";
    default:
        return toString(number) + "th";
    }
}
