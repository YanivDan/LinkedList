#include "link.h"


Link::Link()
{
    head = NULL;
    tail = NULL;
}


Link::~Link()
{
}


void Link::Create_node(int &value)
{
    node *temp = new node;
    
    temp -> data = value;
    temp -> next = NULL;
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
    
    list_len++;

    // delete from the heap
    delete temp;
}


void Link::Insert_At(int &pos, int &val)
{
    if (pos > list_len)
    {
        printf("[-] Out of bound list \n");
        return;
    }
    
    node *pre = new node;
    node *current = new node;
    node *temp = new node;
    
    current = head;
    
    for(int i = 1; i < pos; i++)
    {
      pre = current;
      current = current -> next;
    }
    
    temp -> data = val;
    pre -> next = temp;	
    temp -> next = current;

    list_len++;

    // delete from the heap
    delete pre;
    delete current;
    delete temp;
}


void Link::Delete_At(int &pos)
{
    if (pos > list_len)
    {
        printf("[-] Out of bound list \n");
        return;
    }
    
    else if (pos == 1)
    {
        Delete_first();
        list_len--;
        return;
    }

    else if (pos == list_len)
    {
        Delete_last();
        list_len--;
        return;
    }

    node *current = new node;
    node *pre = new node;
    
    current = head;

    for (int i = 1; i < pos; i++)
    {
        pre = current;
        current = current -> next;
    }
    
    pre -> next = current -> next;
    current -> next = NULL;

    list_len--;

    // delete from the heap
    delete current;
    delete pre;
}


void Link::Delete_first()
{
    node *temp = new node;
    
    temp = head;
    head = head -> next;
    
    // delete from the heap
    delete temp;
}


void Link::Delete_last()
{
    node *current = new node;
    node *pre = new node;
    
    current = head;
    
    while(current -> next != NULL)
    {
      pre = current;
      current = current -> next;	
    }
    
    tail = pre;
    pre -> next = NULL;
    
    // delete from the heap
    delete current;
}

// TODO -->
void Link::Delete_by_value(int &val)
{

}


int Link::Get_Value(int &pos)
{
    if (pos > list_len)
    {
        printf("[-] Out of bound list \n");
        return;
    }
    
    node *temp = new node;
    
    temp = head;

    for (int  i = 1; i < pos; i++)
    {
        temp = temp -> next;
    }
    
    int val = temp -> data;

    // delete from the heap
    delete temp;

    return val;
}


void Link::Update_value_by_index(int &pos, int &val)
{
    if (pos > list_len)
    {
        printf("[-] Out of bound list \n");
        return;
    }
    
    node *temp = new node;

    temp = head;

    for (int i = 1; i < pos; i++)
    {
        temp = temp -> next;
    }
    
    temp -> data = val;

    // delete from the heap
    delete temp;
}


int * Link::Find_index_by_value(int &val) // return a array of index of the value
{
    node *temp = new node;

    temp = head;
    
    // TODO --- needed to be memset! 
    int index_arr [list_len]; 
    
    // int to set the index in the array 
    int i = 1;

    for (int index = 1; index < list_len; index++)
    {
        if (temp -> data == val)
        {
            index_arr[i] = index;
            i++;
        }
        temp = temp -> next;
    }
    
    // delete from the heap
    delete temp;

    // the number of app of val in the list
    index_arr[0] = i; 

    // if the value isn't in the list, must be at least > 0
    if (index_arr[1] == 0) 
    {
        printf("[-] The value was not found in the list \n");
        return;
    }

    return index_arr;
}


int Link::Get_list_len()
{
    return list_len;
}


void Link::Swap_data(node *a, node *b)
{
    int temp = a -> data; 
    a -> data = b -> data; 
    b -> data = temp; 

    printf("[-] Swaped \n");
}


void Link::Sort_list()
{
    if (head == NULL)
    {
        printf("[-] Sorted \n");
        return;
    }

    node *pre = new node;
    node *current = new node;
    
    pre = head;
    current = head -> next;

    for (int i = 1; i < list_len; i++)
    {
        if (pre -> data > current -> data)
        {
            Swap_data(pre, current);
        }
        pre = current;
        current = current -> next;
    }
    
    printf("[-] Sorted \n");
}


void Link::Display_list()
{
    node *temp = new node;
    temp = head;
    int index = 1;
    while(temp != NULL)
    {
        printf("index %d: ,the value is: %d \n", index, temp -> data);
        temp = temp -> next;
    }

    // delete from the heap
    delete temp;
}