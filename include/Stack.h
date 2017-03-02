#ifndef STACK_H
#define STACK_H

#include <list>

using namespace std;

template<class T>
class Stack
{
    public:
        Stack() {};
        virtual ~Stack() {};

        // check if the Stack is empty
        bool isEmpty()
        {
            return m_List.empty();
        }

        // get the number of T's in the Stack
        int size()
        {
            return m_List.size();
        }

        // get the T at the top of the Stack
        T top()
        {
            return *(m_List.begin());
        }

        // add a T to the top of the Stack
        bool push(T t)
        {
            m_List.push_front(t);
            return true;
        };

        // remove the T from the top of the Stack
        bool pop()
        {
            if (m_List.empty()) return false;

            m_List.pop_front();
            return true;
        };
    private:
        list<T> m_List;
};

#endif // STACK_H
