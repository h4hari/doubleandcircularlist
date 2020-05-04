#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *next;
}*last;


class circularlist
{
    public:
        void createnode(int value);
        void addbegin(int value);
        void addafter(int value, int position);
        void deleteelement(int value);
        void displaylist();
        circularlist()
        {
            last = NULL;
        }
};


int main()
{
    int ch, element, p;
    circularlist cl;
    while (1)
    {
        cout<<"Circular Linked List"<<endl;
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at beginning"<<endl;
        cout<<"3.Add after"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.createnode(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cl.addbegin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>p;
            cl.addafter(element, p);
            cout<<endl;
            break;
        case 4:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.deleteelement(element);
            cout<<endl;
            break;

        case 5:
            cl.displaylist();
            break;
        }
    }
    return 0;
}


void circularlist::createnode(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}


void circularlist::addbegin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}


void circularlist::addafter(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;

    if (s == last)
    {
        last=temp;
    }
}


void circularlist::deleteelement(int value)
{
    struct node *temp, *s;
    s = last->next;

    if (last->next == last && last->info == value)
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value)
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {

        if (s->next->info == value)
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    }

    if (s->next->info == value)
    {
        temp = s->next;
        s->next = last->next;
        free(temp);
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}



void circularlist::displaylist()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}
