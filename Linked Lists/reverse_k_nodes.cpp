#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
void insh(node*&head,int data )
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node *x=new node(data);
    x->next=head;
    head=x;

}
void printl(node *head)
{
    if(head==NULL)
    {
        return;
    }
    cout<<head->data<<"->";
    printl(head->next);
}
node* reversel(node *head)
{
    if(head->next==NULL)
    {
        return head;
    }

    node *shead=reversel(head->next);

    node *temp=head->next;
    temp->next=head;
    head->next=NULL;

    return shead;


}
node* reversek(node *head,int k)
{
    int count =1;
    node *current=head;
    node *n=NULL;
    node *previous=NULL;
    while(current!=NULL&&count<=k)
    {
        n=current->next;
        current->next=previous;
         previous=current;
        current=n;

        count++;
    }

    if(n!=NULL)
   head->next=reversek(n,k);
    return previous;
}

void pairswap(node *head)
{

    node* temp=head;


    while(temp->next!=NULL&&temp->next->next!=NULL)
    {
        node *z=temp->next;
       swap(temp->data,z->data);
       temp=temp->next->next;

    }

}
void removedup(node *head)
{
    for(node* i=head;i->next!=NULL;i=i->next)
    {
        for(node *j=i;j->next!=NULL;j=j->next)
        {
            node *temp=j->next;

            if(i->data==j->data)
            {
                if(temp->next!=NULL)
                {
                j->next=temp->next;
                delete(temp);
                }

            }


        }
    }
}

int main()
{

    node *head=NULL;
    insh(head,10);
       insh(head,9);
          insh(head,9);
            insh(head,10);
                insh(head,6);
                insh(head,4);
                   insh(head,4);
                   removedup(head);
                                    // pairswap(head);
                   printl(head);
                   cout<<endl;
                 node* h= reversek(head,3);
                   printl(h);

                   return 0;
}

