#include <iostream>
using namespace std;
class node
{
  public:
  node *next;
  int data;
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
node* add(node *head1,node *head2)
{
    node *head=NULL;
    int carry=0;
    while(head1!=NULL&&head2!=NULL)
    {
      int sum=head1->data+head2->data+carry;
      if(sum>=10)
      { int x=sum-10;
          insh(head,x);
          carry=1;

      }
      else
      {
          insh(head,sum);
          carry=0;
      }
      head1=head1->next;
      head2=head2->next;
    }
    while(head1!=NULL)
    {
        int sum=head1->data+carry;
             if(sum>=10)
      { int x=sum-10;
          insh(head,x);
          carry=1;

      }
        else
      {
          insh(head,sum);
          carry=0;
      }
      head1=head1->next;

    }

     while(head2!=NULL)
    {
        int sum=head2->data+carry;
             if(sum>=10)
      { int x=sum-10;
          insh(head,x);
          carry=1;

      }
        else
      {
          insh(head,sum);
          carry=0;
      }
      head2=head2->next;

    }
    if(carry)
    {
        insh(head,carry);
    }
    return head;
}
int main()
{
    node *x1=NULL;
    node *x2=NULL;

    insh(x1,5);
    insh(x1,6);
     insh(x1,3);
      insh(x1,2);

    printl(x1);
    cout<<endl;
    insh(x2,3);

    insh(x2,3);
    printl(x2);
    cout<<endl;
    node *su=add(x1,x2);
    printl(su);
    return 0;
}
