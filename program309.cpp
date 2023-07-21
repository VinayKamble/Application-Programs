#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class SinglyLL
{
    private:
        PNODE First;       
        int iCount;       

    public:
        SinglyLL();
        ~SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

void SinglyLL:: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;   

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)  
    {
        First = newn;
    }
    else   
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL:: InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;    

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)   
    {
        First = newn;
    }
    else    
    {
        PNODE temp = First;

        while(temp ->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

void SinglyLL:: InsertAtPos(int no, int ipos)
{}

void SinglyLL:: DeleteFirst()
{
    if(First == NULL)           
    {
        return;
    }
    else if(First->next == NULL)    
    {
        delete First;      
        First = NULL;
    }
    else       
    {
        PNODE temp = First;

        First = First -> next;
        delete temp;
    }
    iCount--;
}

void SinglyLL:: DeleteLast()
{
    if(First == NULL)          
    {
        return;
    }
    else if(First->next == NULL)   
    {
        delete First;      
        First = NULL;
    }
    else      
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

void SinglyLL:: DeleteAtPos(int ipos)
{}

void SinglyLL:: Display()
{
    PNODE temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp -> next;
    }
    cout<<" NULL"<<"\n";
}

int SinglyLL:: Count()
{
    return iCount;
}

SinglyLL:: SinglyLL()
{
    cout<<"Inside constructor\n";

    First = NULL;
    iCount = 0;
}

SinglyLL:: ~SinglyLL()
{
    cout<<"Inside destructor\n";
}

int main()
{
    int iRet = 0;

    SinglyLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

   obj1.DeleteFirst();
   obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}