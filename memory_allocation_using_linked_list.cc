#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int size;
    bool allocated_or_not;
    struct Node *next;
    struct Node *prev;
    int data;
}*head=NULL;

void Insert(int x, int y)
{
    struct Node *t,*last;
    t=new Node;
    t->data=x;
    t->size=y;
    t->allocated_or_not=false;
    if(head==NULL)
    {
        t->next=NULL;
        t->prev=NULL;
        head=t;
        last=t;
    }
    else
    {
        t->next=NULL;
        last->next=t;
        t->prev=last;
        last=t;
    }
    
}

int firstFit(int x)
{
    struct Node *p=head;
    while(p)
    {
        if(p->allocated_or_not==false)
        {
            if(p->size<=x)
            {
                p->allocated_or_not=true;
                cout<<"Memory is allocated\n";
                return p->size;
                break;
            }
        }
        else
        {
            p=p->next;
        }
    }
    if(p->allocated_or_not=false)
    {
        cout<<"Required is greater than highest size of memory\n";
    }
    return 0;
}

int nextFit(int x)
{
    struct Node *p=head,*q;
    while(p->allocated_or_not=false)
    {
        p=p->next;
    }
    q=p;
    while(q)
    {
        if(q->size<=x)
        {
            q->allocated_or_not=true;
            cout<<"Memory is allocated\n";
            return p->size;
            break;
        }
    }
        if(q->allocated_or_not=false)
    {
        cout<<"Required is greater than highest size of memory\n";
    }
    return 0;
}

int  bestFit(int x)
{
    struct Node *p;
    int n;
    vector<int>ans;
    p=head;
    while(p)
    {
        if(p->size<x)
        {
            continue;
        }
        else
        {
            n=p->size-x;
            ans.push_back(n);
        }
    }
    sort(ans.begin(), ans.end());
    struct Node *q=head;
    while(q)
    {
        if(ans[0]+x==q->size)
        {
            q->allocated_or_not=true;
            return q->size;
            break;
        }
        else 
        {
            q=q->next;
        }
    }
    return 0;
}

int main()
{
    // Making of doubly link list
    Insert(0,4);
    Insert(1,8);
    Insert(2,16);
    Insert(3,32);
    Insert(4,64);
    Insert(5,128);
    Insert(6,256);
    Insert(7,512);

// Taking input from the user
    while(true)
    {
        cout<<"Enter required number of size"<<"\n";
        int n;
        cin>>n;
        cout<<"Enter allocation type 1 for firsst fit, 2 for next fit and 3 for best fit :-  ";
        int allocation_type;
        cin>>allocation_type;
        if(allocation_type==1) firstFit(n);
        else if(allocation_type==2) nextFit(n);
        else if(allocation_type==3) bestFit(n);
        else 
        {
            cout<<"Oops!! Invalid Input !!";
            break;
        }
        cout<<"Press 0 for next input and any other key for exit :- ";
        int answer_output;
        cin>>answer_output;
        if(answer_output==0) continue;
        else break;
    }
    return 0;
}