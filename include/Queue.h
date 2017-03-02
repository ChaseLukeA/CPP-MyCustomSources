#ifndef QUEUE_H
#define QUEUE_H

#include <list>

using namespace std;

template<class T>
class Queue
{
    public:
        Queue() {};
        virtual ~Queue() {};

        // check if the Queue is empty
        bool isEmpty()
        {
            return m_List.empty();
        }

        // get the number of T's in the Queue
        int size()
        {
            return m_List.size();
        }

        // get the T at the beginning of the Queue
        T front()
        {
            return *(m_List.begin());
        }

        //add a T to the end of the Queue
        bool enQueue(T t)
        {
            m_List.push_back(t);
            return true;
        };

        // remove the T from the beginning of the Queue
        bool deQueue()
        {
            if (m_List.empty()) return false;

            m_List.pop_front();
            return true;
        };
    private:
        list<T> m_List;
};

#endif // QUEUE_H
