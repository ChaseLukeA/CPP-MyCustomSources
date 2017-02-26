#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
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

    cout << endl << endl << "Testing Iterator..." << endl << endl;

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

    cout << endl << "Number " << choice << " is \"" << (*itr) << "\"" << endl;

    return 0;
}
