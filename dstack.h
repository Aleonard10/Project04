#ifndef DSTACK_H
#define DStACK_H

class dstack
{
    public:
        dstack();
        ~dstack();
        void push(double value);
        bool pop(double &value);
        bool empty();
        void print();
        int size();
        void setSize(bool addOrSubtract);



    private:
        class Node
        {
            public:
                Node(double value, Node* next)
                {
                    m_value = value;
                    m_next = next;
                }
                double m_value;
                Node* m_next;
        };
        Node* m_head;
        int Size = 0;

};
#endif
