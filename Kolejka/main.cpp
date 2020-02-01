#include <QCoreApplication>
#include <iostream>
using namespace std;

template <class T> class List;
template <class T> class Link{

    T value;
    Link<T>* next;
    //Link<T>* previous;

public:
    Link(T v, Link<T>* n):value(v),next(n) {
    }
    Link<T>& getAddres(){
        return &this;
    }
    friend  class List<T>;

};

template <class T> class List{

    Link<T>* First;
public:
    List():First(nullptr){}

    void add(T value){
            First = new Link<T>(value, First);
    }

    T firstElement(){
        return First->value;
    }

    void showList(){
        for(Link<T>* p=First; p ;p=p->next )
            cout << p->value <<endl;
    }

    void deleteFirst(){
        Link<T>* todelete;
        for( Link<T>* p=First;p;p=p->next ){

            //cout << "tak istnieję"<<endl;

            if  (p->next->next==nullptr)
            {
                cout << "usuwam:" <<p->value<< endl;
                delete p->next;
                p = nullptr;
                return;
            }

        }

    }

};


int main(int argc, char *argv[])
{
    List<double> lista;

    lista.add(5.5);
    lista.add(6.8);
    lista.add(7.2);

    lista.showList();
    lista.deleteFirst();
    cout << "Po usunieciu"<<endl;
    lista.showList();

    return 0;
}
