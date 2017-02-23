#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<string> romanNumberals;

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

    romanNumberals.addLast(ii);
    romanNumberals.addLast(iii);
    romanNumberals.addLast(v);
    romanNumberals.addBefore(iv, 2);
    romanNumberals.addFirst(i);
    romanNumberals.addAfter(vi, 8);
    romanNumberals.addLast(ix);
    romanNumberals.addAfter(vii, 5);
    romanNumberals.addBefore(viii, 7);
    romanNumberals.addFirst(n);
    romanNumberals.addLast(n);
    romanNumberals.removeAt(0);
    romanNumberals.addAfter(x, 10);
    romanNumberals.removeAt(9);
    romanNumberals.removeAt(10);

    cout << "Roman Numerals:" << endl;
    romanNumberals.print();

    delete &romanNumberals;

    cout << endl << "Roman Numerals:" << endl;
    romanNumberals.print();

    return 0;
}
