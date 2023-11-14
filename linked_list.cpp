#include<iostream>
using namespace std;
class node
{
    public:
        int value;
        node *next;
        node(int data):value(data),next(nullptr){};
};
class link_list
{
    private:
        node *head;
        node* last;
        int length;
        int partition(int first, int last);
        void sorthelper(int firt, int last);
        void swap(int index1, int index2);
    public:
        link_list()
        {
            head=nullptr;
            last=nullptr;
            length=0;
        }
        link_list(int length):head(nullptr),last(nullptr),length(0) {
            for(int i=0; i<len(); i++)
            {
                push_back(0);
            }
        }
        link_list(initializer_list<int> value):head(nullptr),last(nullptr),length(0){
            for(int key:value)
            {
                push_back(key);
            }
        }
        void push_front(int val);
        void push_back(int val);
        void print();
        void insert_at_index(int index, int val);
        void delete_at_index(int index);
        void pop_front();
        void pop_back();
        int& operator[](const int index);
        int len();
        void sort();
        class iterator{
            private:
            node* current;
            public:
            iterator(node* start):current(start){};
            int& operator*(){
                return current->value;
            }
            iterator& operator++()
            {
                current=current->next;
                return *this;
            }
            bool operator!=(const iterator &other)const{
                return current!=other.current;
            }
        };
        iterator begin(){
            return iterator(head);
        }
        iterator end()
        {
            return iterator(nullptr);
        }
};
int main()
{
    link_list x={1,3,5,11,-1,11,0};
    x.sort();
    
    x.print();
}
void link_list::push_front(int val)
{
    
    node *new_node= new node(val);
    if(head==nullptr)
    {
        head=new_node;
        last=new_node;
        length++;
        return;
    }
    else
    {
        new_node->next=head;
        head=new_node;
        length++;
    }
}
void link_list::print(){
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void link_list::insert_at_index(int index, int data){
    int length=len();
    if(index<0||index>length)
    {
        throw out_of_range("Index out of bounds");
    }
    if(index==length-1){
        push_back(data);
        return;
    }
    if(index==0)
    {
        push_front(data);
        return;
    }
    node* new_node=new node(data);
    node* temp=head;
    for(int i=0; i<index-2; i++)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void link_list::push_back(int val)
{
    node* new_node=new node(val);
    if(head==nullptr)
    {
        head=new_node;
        last=new_node;
        length++;
        return;
    }
    else
    {
        last->next=new_node;
        last=new_node;
        length++;
    }
}

void link_list::delete_at_index(int index)
{
    if(head==nullptr)
    {
        throw runtime_error("No node to delete");
    }
    if(index<0||index>len())
    {
        throw out_of_range("Index out of bounds, valid index(0~"+to_string(len()-1)+")");
    }
    else
    {
        node *temp=head;
        for(int i=0; i<index-1;i++)
        {
            if(temp->next!=nullptr)
            {
                temp=temp->next;
            }
        }
        node * temp2=temp->next;
        temp->next=temp->next->next;
        delete temp2;
        length--;
    }
}
void link_list::pop_front()
{
    
    if(head==nullptr)
    {
       throw runtime_error("No node to delete");
    }
    else
    {
        node *t=head;
        head=t->next;
        delete t;
    }
}
void link_list::pop_back()
{
    if(head==nullptr)
    {
        throw runtime_error("No node to delete");
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
int& link_list::operator[](int index){
    if(index<0||index>len())
    {
        cerr<<"Index Out of Bound"<<endl;
        exit(1);
    }
    if(index==len()-1)
    {
        return last->value;
    }
    node* temp=head;
    for(int i=0; i<index; i++)
    {  
        temp=temp->next;
    }
    return temp->value;
}
int link_list::len(){
    return length;
}
void link_list::swap(int index1, int index2)
{
    int temp=this->operator[](index1);
    this->operator[](index1)=this->operator[](index2);
    this->operator[](index2)=temp;
}
int link_list::partition(int first, int last){
    int pivot=this->operator[](last);
    int i=first-1;
    for(int j=first; j<last; j++) {
        if(this->operator[](j)<pivot)
        {
            i++;
            swap(i,j);
        }
    }
    swap(i+1,last);
    return i+1;
}
void link_list::sorthelper(int first, int last){
    if(first<last)
    {
        int pivot_index=partition(first,last);
        sorthelper(first,pivot_index-1);
        sorthelper(pivot_index+1,last);
    }
    return;
}
void link_list::sort(){
    sorthelper(0,len()-1);
}