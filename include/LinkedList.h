#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifndef null
#define null 0
#endif

#include <iostream>

using namespace std;

// LinkedList Declarations
//------------------------------------------------------------------------------------------------//
template <class T>
class LinkedList
{
    public:
    LinkedList() : m_Head(null), m_Tail(null) {};
		LinkedList(LinkedList& nodes);
    virtual ~LinkedList();

		bool addFirst(const T &element);
		bool addLast(const T &element);
		bool addBefore(const T &element, int position);
		bool addAfter(const T &element, int position);
		bool removeFirst();
		bool removeLast();
		bool removeAt(int position);
		bool isEmpty() const { return m_Head == null; };
		void print();

    private:
        class Node
        {
            public:
                Node(T element = 0, Node *next = null) : m_Element(element), m_Next(next) {}

        				T m_Element;
        				Node* m_Next;
		    };

    		Node* m_Head;
    		Node* m_Tail;

    		const LinkedList& operator = (const LinkedList& nodes);
};

// LinkedList Definitions
//------------------------------------------------------------------------------------------------//
// Constructor that makes a deep copy of the specified LinkedList
template<class T>
inline LinkedList<T>::LinkedList(LinkedList& nodes) : m_Head(null), m_Tail(null)
{
    if (!nodes.isEmpty())
    {
        Node* originalNode = nodes.m_Head;
        Node* copiedNode = new Node(nodes.m_Head->m_Element, null);

        m_Head = copiedNode;
        m_Tail = copiedNode;

        while (originalNode->m_Next)
        {
            originalNode = originalNode->m_Next;

            Node* newCopiedNode;
            newCopiedNode = new Node(originalNode->m_Element, null);

            copiedNode->m_Next = newCopiedNode;
            m_Tail = newCopiedNode;
            copiedNode = copiedNode->m_Next;
        }
    }
}

// Destructor removes all nodes
template<class T>
inline LinkedList<T>::~LinkedList()
{
    while (!isEmpty()) removeFirst();
}

// Add a node to the beginning of the list
template<class T>
inline bool LinkedList<T>::addFirst(const T &element)
{
    Node *newHead = new Node(element, null);

    if (!m_Head)
    {
        m_Tail = newHead;
        newHead->m_Next = null;
    }
    else
    {
        newHead->m_Next = m_Head;
    }
    m_Head = newHead;

    return true;
}

// Add a node to the end of the list
template<class T>
inline bool LinkedList<T>::addLast(const T &element)
{
    Node *newTail = new Node(element, null);

    if (m_Tail) m_Tail->m_Next = newTail;

    if (!m_Head) m_Head = newTail;

    m_Tail = newTail;

    return true;
}

// Add a node before the specified position
template<class T>
inline bool LinkedList<T>::addBefore(const T &element, int position)
{
    if (position < 0) return false;
    if (position == 0) this->addFirst(element);

    Node *newElement = new Node(element, null);

    Node* current = m_Head;
    Node* previous = current;
    int index = 1;

    while (current->m_Next && index < position) {
        previous = current;
        current = current->m_Next;
        index++;
    }

    // if requested position is greater than or equal to the total number of elements, just append it
    if (!current->m_Next) { this->addLast(element); return true; }

    // set new node's next
    newElement->m_Next = current->m_Next;

    // set previous node's next
    current->m_Next = newElement;

    return true;
}

// Add a node after the specified position
template<class T>
inline bool LinkedList<T>::addAfter(const T &element, int position)
{
    if (position < 0) return false;

    Node *newElement = new Node(element, null);

    Node* current = m_Head;
    Node* previous = current;
    int index = 0;

    // find the requested position
    while (current->m_Next && index < position) {
        previous = current;
        current = current->m_Next;
        index++;
    }

    // if requested position is greater than or equal to the total number of elements, just append it
    if (!current->m_Next) { this->addLast(element); return true; }

    // set new node's next
    newElement->m_Next = current->m_Next;

    // set previous node's next
    current->m_Next = newElement;

    return true;
}

// Remove first node from the list
template<class T>
inline bool LinkedList<T>::removeFirst()
{
    if (isEmpty()) return false;

    Node* newFirst = m_Head->m_Next;
    delete m_Head;
    m_Head = newFirst;

    return true;
}

// Remove last node from the list
template<class T>
inline bool LinkedList<T>::removeLast()
{
    if (isEmpty()) return false;

    Node* current = m_Head;
    Node* previous = current;

    while (current->m_Next)
    {
        previous = current;
        current = current->m_Next;
    }

    // check if only element in the list and if it is, set head to null
    if (current == previous) m_Head = null;

    // delete last element
    delete current;
    // set tail to previous to last (if only element, tail is also set to null because it was same as current)
    m_Tail = previous;
    // set previous to last's next to null (if only element, does nothing since previous is now null)
    previous->m_Next = null;

    return true;
}

// Remove node at specified position
template<class T>
inline bool LinkedList<T>::removeAt(int position)
{
    if (position < 0 || isEmpty()) return false;

    if (position == 0) { this->removeFirst(); return true; }

    Node* current = m_Head;
    Node* previous = current;
    int index = 0;

    while (current->m_Next && index < position)
    {
        previous = current;
        current = current->m_Next;
        index++;
    }

    // out-of-range check (reached end of list and position still not reached)
    if (!current->m_Next && index < position) return false;

    // is specified position the last node?
    if (current == m_Tail) { this->removeLast(); return true; }

    previous->m_Next = current->m_Next;
    delete current;

    return true;
}

// Print the entire list of nodes
template<class T>
inline void LinkedList<T>::print()
{
    if (isEmpty()) { cout << "The list is empty." << endl; return; }

    Node* current = m_Head;

    while (current->m_Next)
    {
        cout << current->m_Element << endl;
        current = current->m_Next;
    }
    cout << current->m_Element << endl;
}

#endif // LINKEDLIST_H
