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
node* sub(node *head1,node *head2)
{
    node *head=NULL;

    while(head1!=NULL&&head2!=NULL)
    {
      int dif=head1->data-head2->data;
      if(dif<0)
      {
          dif+=10;
      if(head1->next=NULL)
      {
        head1->next->data-=1;
          insh(head,dif);
      }

      else
      {
          dif-=10;
          insh(head,dif);
      }

      }
      else
      {
          insh(head,dif);

      }
      head1=head1->next;
      head2=head2->next;
    }
    while(head1!=NULL)
    {

     int dif=head1->data;
      if(dif<0)
      {
          dif+=10;
        head1->next->data-=1;
          insh(head,dif);

      }
      else
      {
          insh(head,dif);

      }
      head1=head1->next;

    }
    while(head2!=NULL)
    {


     if(head2->next==NULL)
     {
         int x=-1*head2->data;
         insh(head,x);
     }
     else
        insh(head,head2->data);
    head2=head2->next;
    }
    return head;


}
int main()
{
    node *x1=NULL;
    node *x2=NULL;

   insh(x1,5);
    insh(x1,7);
     insh(x1,6);
      insh(x1,4);

    insh(x2,5);
    insh(x2,5);
    insh(x2,9);

    insh(x2,4);

    node *su=sub(x1,x2);
    printl(su);
    return 0;
}
