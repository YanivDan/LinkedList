#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *next;
};

class Link
{
    private:
    node *head, *tail;
    int list_len = 0;
        
    public:
        Link(); // constructor
        ~Link();
        void Create_node(int &value); // append node to the end
        void Insert_At(int &position, int &value); // the insert is after the position
        void Delete_At(int &position);
        void Delete_first(); // delete the first node
        void Delete_last(); // delete the last node
        void Delete_by_value(int &value); // TODO -->
        int Get_Value(int &position); // get the value at certain position
        void Update_value_by_index(int &position, int &value);
        int * Find_index_by_value(int &value); // return's index of first show of a value
        int Get_list_len();
        void Swap_data(node *a, node *b);
        void Sort_list(); // bobule sort
        void Display_list();
};


#endif
