// Specific code Queue
#include<iostream>

using namespace std;

#pragma pack(1)
class Queuenode
{
    public:
        char data;
        Queuenode * next;

        Queuenode(char no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Queue
{
    private:
        Queuenode * first;
        int iCount;
        
    public:
        Queue();
        void enqueue(char);     // InsertLast
        char dequeue();         // DeleteFirst 
        void Display();
        int Count();
};

Queue::Queue()
{
    cout<<"Queue gets created successfully...\n";
    this->first = NULL;
    this->iCount = 0;
}

void Queue::enqueue(char no)
{
    Queuenode * newn = NULL;
     Queuenode * temp = this->first;

    newn = new Queuenode(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else 
    {   
       while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    this->iCount++;
}

char Queue ::dequeue()
{
    char Value = 0;
    Queuenode * temp = this->first;

    if(this->first == NULL)
    {
        cout<<" Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    
    delete temp;

    this->iCount--;

    return Value;

}

void Queue:: Display()
{
    Queuenode * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return this->iCount;
}


int main()
{
    Queue * qobj = new Queue();

    qobj->enqueue('A');
    qobj->enqueue('B');
    qobj->enqueue('C');
    qobj->enqueue('D');
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    qobj->enqueue('M');
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";


    delete qobj;
    
    return 0;
}