#include <iostream>
#include <cassert>

using namespace std;

class link {
    double value;
    link *next;
    link(double val, link *ptr): value(val), next(ptr) {}
public:
    friend class list;
};

class list {
    link *first;
public:
    list(): first(nullptr) {}
    void showAll() {
           //for(link *ptr=first;ptr;ptr=ptr->next)
            //cout << ptr->value << " ";

        for( link *p=first;p!=nullptr;p=p->next ){
            cout << p->value <<endl;
        }

    }
    void add(double val) {


        first=new link (val,first);

    }
    void rmv(double val) {
        /*
        link *ptr1;
        link *ptr2;
        for (ptr1=first;ptr1;ptr1=ptr1->next)
        {
            ptr2=ptr1->next;
            if (ptr2->value==val)
            {
                ptr1->next=ptr2->next;
                break;
            }
            delete ptr2;
        }

        */

        link *p1;
        link *p2;
        for(p1=first;p1;p1=p1->next){
            p2=p1->next;
            if(p2->value==val)
            {
                p1->next=p2->next;
                break;
            }
            delete p2;
        }


    }
};



int main() {
    list lista;
    int n;
    double toAdd;
    cout << "Add: ";
    cin >> n;
    while(n--)
    {
        cout <<endl<< "to add: ";
        cin >> toAdd;
        lista.add(toAdd);
    }
    lista.showAll();
    cout << "remove" <<endl;
    cin >> n;
    while(n--)
    {
        cout <<endl<< "to remove: ";
        cin >> toAdd;
        lista.rmv(toAdd);
    }
    lista.showAll();
}
