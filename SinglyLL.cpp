#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
}NODE,*PNODE;
class SinglyLL
{
    private:
    PNODE first;
    int size;
    public:

    SinglyLL()
    {
        first=NULL;
        size=0;

    }
    void Display()
    {
        PNODE temp=first;
        while(first!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;

        }
        cout<<"\n";
    }
    int Count()
    {
        return size;
    }
    void InsertFirst(int no)
    {

        PNODE newn=new NODE;

        newn->data=no;
        newn->next=NULL;

        if(first==NULL)
        {
            first=newn;
        }
        else 
        {
            newn->next=first;
            first=newn;
        }
        size++;
    }

    void InsertLast(int no)
    {
         PNODE temp=first;

        PNODE newn=new NODE;

        newn->data=no;
        newn->next=NULL;

        if(first==NULL)
        {
            first=newn;
        }
        else 
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;

        }
        size++;
    }
    void InsertAtPos(int no,int iPos)
    {
        if(iPos>1 && iPos<size+1)
        {
            return;
        }
        if(iPos==1)
        {
            InsertFirst(no);
        }
        else if(iPos==size)
        {
            InsertLast(no);
        }
        else 
        {

            PNODE newn=new NODE;
            newn->data=no;
            newn->next=NULL;


            PNODE temp=first;
            for(int i=1;i<iPos-1;i++)
            {
                temp=temp->next;

            }
            newn->next=temp->next;
            temp->next=newn;



        }
        size++;

    }
    void DeleteFirst()

    {
        PNODE temp=first;
        if(first!=NULL)
        {
            first=first->next;
            delete temp;
            size--;
        }
    }
    void DeleteLast()
    {
        PNODE temp=first;
        if(first==NULL)
        {
            return;
        }
        else if(first->next!=NULL)
        {
            delete first;
            first=NULL;
            size--;

        }
        else 
        {
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next=NULL;
            size--;

        }

    }
    void DeleteAtPos(int iPos)
    {
        if(iPos>1 && iPos<size+1)
        {
            return;
        }
        if(iPos==1)
        {
            DeleteFirst();
        }
        else if(iPos==size)
        {
            DeleteLast();
        }
        else 
        {
            PNODE temp=first;
            for(int i=1;i<iPos-1;i++)
            {
                temp=temp->next;


            }
            temp->next=temp->next->next;
            delete temp->next;
            size--;

            
        }
    }


};
int main()
{
    SinglyLL obj;
    int iret=0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.DeleteFirst();

    obj.Display();
    iret=obj.Count();
    obj.Display();
    cout<<"Number of elements are:"<<iret<<"\n";

    return 0;

}

