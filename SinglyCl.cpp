#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
}NODE,*PNODE;

class SinglyCL
{
    private:
    PNODE first;
    PNODE last;
    int Size;

    public:
    SinglyCL()
    {
        first=NULL;
        last=NULL;
        size=0;
    }
    void Display()
    { 
        PNODE temp=first;
        while(first!=NULL)
        {
             cout<<temp->data"\t";
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

        if((first==NULL) && (last==NULL))
        {
            first=newn;
            last=newn;
        }
        else 
        {
            newn->next=first;
            first=newn;

        }
        last->next=first;
        size++;



    }
    void InsertLast(int no)
    {
         PNODE newn=new NODE;
        newn->data=no;
        newn->next=NULL;

        if((first==NULL) && (last==NULL))
        {
            first=newn;
            last=newn;
        }
        else
        {
            last->next=newn;
            last=newn;

            
        }
        last->next=first;
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
            PNODE temp=first;
            PNODE newn=new NODE;
            newn->data=no;
            newn->next=NULL;

            while(temp->next!=NULL)
            {
                temp=temp->next;

            }
            newn->next=temp->next;
            temp->next=newn;
        }
        last->next=first;
        size++;

    }
    void DeleteFirst()
    {
        if((first==NULL) && (last==NULL))
        {
            return;
        }
        else if(first==last) 
        {
            delete first;
            first=NULL;
            last=NULL;

        }
        else 
        {
            first=first->next;
            delete last->next;
            last->next=first;
        }
        size--;
    }
    void DeleteLast()
    {
        
        if((first==NULL) && (last==NULL))
        {
            return;
        }
        else if(first==last) 
        {
            delete first;
            first=NULL;
            last=NULL;

        }
        else 
        {
             while(temp->next!=NULL)
             {
                  temp=temp->next;
             }
             delete temp;
             last=temp;

             temp->next=first;

        }
        size--;


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
        else if(iPos==last)
        {
            DeleteLast();
        }
        
        PNODE temp=first;
        for(int i=0;i<iPos-1;i++)
        {
            temp=temp->next;

            
        }
        temp->next=temp->next->next;
        delete temp->next;
        
    }
    last->next=first;
    size--;



};
int main()
{
    SinglyCL obj;
    int iRet=0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.DeleteFirst();
    obj.InsertLast(101);

    obj.D






}
