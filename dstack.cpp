#include <iostream>
#include "dstack.h"

using namespace std;

dstack::dstack()
{
    m_head = NULL;

}

dstack::~dstack()
{
    Node *ptr = m_head;
    while(ptr != NULL)
    {
        Node *temp;
        temp = ptr;
        ptr = ptr->m_next;
        delete temp;
    }

}

void dstack::push(double value)
{
    m_head = new Node(value, m_head);
    Size++;

    /* This code is for push at end of linked list
    Node *ptr = m_head;
    if(ptr == NULL)
    {
        m_head = new Node(value, m_head);
    }
    else
    {
        while (ptr->m_next != NULL)
        {
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node(value, NULL);
    }
    */

}

void dstack::pop(double &value)
{

    Node *temp = m_head;
    value = temp->m_value;
    m_head = temp->m_next;
    delete(temp);
    Size--;
    return;


}

bool dstack::empty()
{
    if (m_head == NULL)
    {
        return true;
    }
    else if (m_head != NULL)
    {
        return false;
    }
    else
    {
        return 0;
    }

}

void dstack::print()
{
    Node *ptr = m_head;
    while(ptr != NULL)
    {
        cout << ptr->m_value << endl;
        ptr = ptr->m_next;
    }
}
int dstack::size()
{
    return Size;
}
