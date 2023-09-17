#include<iostream>
using namespace std;
class node
{
    public:
        int value;
        node *next;
    node(int val);
};
class link_list
{
    private:
        node *head;
    public:
        link_list()
        {
            head=nullptr;
        }
    void insert(int val);
    void insert_at_last(int val);
    void print();
    void insert_at_mid(int position, int val);
    void delete_at_index(int position);
    void delete_at_first();
    void delete_at_last();
};
int main()
{
    link_list x;
    x.insert_at_last(4);
    x.insert_at_last(6);
    cout<<"before deletion :"<<endl;
    x.print();
    cout<<endl;
    cout<<"after deletion :"<<endl;
    x.delete_at_last();
    x.delete_at_last();
    x.print();
    x.delete_at_last();
}
node::node(int val)
{
    value=val;
    next=nullptr;
};
void link_list::insert(int val)
{
    
    node *new_node= new node(val);
    if(head==nullptr)
    {
        head=new_node;
        return;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}
void link_list::print(){
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->value<<"\t";
        temp=temp->next;
    }
}
void link_list::insert_at_last(int val)
{
    node* new_node=new node(val);
    if(head==nullptr)
    {
        head=new_node;
        return;
    }
    else
    {
        node* traverser=head;
        while (traverser->next!=nullptr)
        {
           traverser=traverser->next;
        }
        traverser->next=new_node;
    }
}
void link_list::insert_at_mid(int position, int val)
{
    node *new_node=new node(val);
    if(head==nullptr)
    {
        head=new_node;
    }
    else
    {
        node *temp=head;
        for(int i=0; i<position-1; i++)
        {
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            cout<<"invalid Position"<<endl;
        }
        else
        {
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
}
void link_list::delete_at_index(int position)
{
    if(head==nullptr)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        node *temp=head;
        for(int i=0; i<position-1;i++)
        {
            if(temp->next!=nullptr)
            {
                temp=temp->next;
            }
        }
        node * temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
        

    }
}
void link_list::delete_at_first()
{
    node *t=head;
    if(head==nullptr)
    cout<<"Empty";
    else
    {
        head=t->next;
        delete t;
    }
}
void link_list::delete_at_last()
{
    if(head==nullptr)
    {
        cout<<"empty"<<endl;
        return;
    }
    node *t=head;
    if(t->next==nullptr)
    {
        delete t;
        head=nullptr;
        return;
    }
    while(t->next->next!=nullptr)
    {
        t=t->next;
    }
    delete t->next;
    t->next=nullptr;
}
