#include <iostream>
#include <cassert>
#include <string>

using namespace std;

template <class T> class Link;
template <class T> class List;
template <class T> class Iterator;

// ======================================================================
//                    Template Class list
// ======================================================================
template <class T>
class List {
protected:
    Link <T> *first;                // data field

public:
    List() : first(nullptr) {}      // default constructor
    List(const List &source);       // copy constructor
    virtual ~List() {};                // destructor

    virtual void add(T value);      // insert a new item
    T firstElement() const;        // access the first item
    virtual bool includes(T value) const;  // inclusion test
    bool isEmpty() const;
    virtual void removeFirst();
    friend class Iterator <T>;
};
// ======================================================================
//                    Template Class link
// ======================================================================
template <class T>
class Link {
private:
    T value;
    Link <T> *next;

    Link(T val, Link *ptr) : value(val), next(ptr) { }


public:
    Link <T> *insert(T value);      // after current Link

    friend class List <T>;
    friend class Iterator <T>;
};

// ======================================================================
//                    Template Class link - attributes
// ======================================================================
template <class T> Link <T> * Link <T> ::insert(T value) {
    next = new Link <T>(value, next);
    return next;
}

// ======================================================================
//                    Template Class list - attributes
// ======================================================================
template <class T> void List <T> ::add(T value)
{
    first = new Link <T>(value, first);
}

template <class T> T List <T> ::firstElement() const
{
    assert(first != nullptr);
    return first->value;
}


template <class T> bool List <T> ::isEmpty() const
{
    return first == nullptr;
}


template <class T> bool List <T> ::includes(T value) const
{
    for (Link <T> *p = first; p; p = p->next)
        if (value == p->value)return true;
    return false;
}

template <class T> void List <T> ::removeFirst() {
    assert(first != nullptr);
    Link <T> *ptr = first;  // save pointer to the first item
    first = ptr->next;      // reassign the first node
    delete ptr;
}


// ======================================================================
//                    Class Template Iterator
// ======================================================================
template <class T> class Iterator {
public:
   Iterator(List <T> &aList);
   virtual bool init();
   virtual T operator()();
   virtual bool operator !();
   virtual bool operator++(); // for prefix, for postfix add dummy int
   virtual bool operator++(int);
   virtual void operator=(T value);
protected:
   List <T> &my_list;             // data fields
   Link <T> *previous;
   Link <T> *current;
};


// ======================================================================
//                    Class Template Iterator - attributes
// ======================================================================
template <class T> Iterator <T> ::
   Iterator(List <T> &aList) : my_list(aList){
   init();
}
template <class T> bool Iterator <T> :: init(){
   previous = nullptr;
   current = my_list.first;
   return current != nullptr;
}
template <class T> T Iterator <T> :: operator()(){
   assert(current != nullptr);
   return current->value;
}
template <class T> void Iterator <T> :: operator=(T val){
   assert(current != nullptr);
   current->value = val;
}


template <class T> bool Iterator <T> :: operator++(){
   if (current == nullptr){           // move current pointer
      if (previous == nullptr)        // to next element
         current = my_list.first;
      else
         current = previous->next;
   }
   else {
      previous = current;
      current = current->next;
   }
   return current != nullptr;
} // valid for prefix operator only!

template <class T> bool Iterator <T> :: operator++(int){
   if (current == nullptr){           // move current pointer
      if (previous == nullptr)        // to next element
         current = my_list.first;
      else
         current = previous->next;
   }
   else {
      previous = current;
      current = current->next;
   }
   return current != nullptr;
}

template <class T> bool Iterator <T> :: operator !(){
   if (current == nullptr and previous != nullptr)
      current = previous->next;
   return current != nullptr;       // termination of iterator
}






// ======================================================================
//                            Class Fifo
// ======================================================================

template <class T>
class Fifo : public List<T>{
   Link <T> *first;

public:

   List <T> lista1;
   List <T> lista2;
   Fifo() : first(nullptr) {}
   virtual ~Fifo(){}
   virtual void push(T value);
   virtual void pop();
   T getFirst();
   friend class Iterator <T>;
   //friend ostream &operator <<(ostream &s, Fifo<T>& stosik);
};

// ======================================================================
//                            Fifo Attribiutes
// ======================================================================

template <class T> ostream &operator <<(ostream &s, Fifo<T>& stosik)
{
    Iterator<T> l1(stosik.lista1);
    Iterator<T> l2(stosik.lista2);
    List <T> temp;
    Iterator<T> t(temp);

    for(l1.init();!l1;l1++)
    {
       temp.add( l1() );
    }
    for( t.init();!t;t++ )
    {
        s << t() << " ";
    }
    for(l2.init();!l2;l2++)
    {
       s << l2() << " ";

    }

    return s;
}


template <class T> void Fifo<T> ::push(T value){

    lista1.add(value);

}

template <class T> void Fifo <T> ::pop(){
    if( lista2.isEmpty() ){
        assert(!lista1.isEmpty());
        while(!lista1.isEmpty()){
            lista2.add( lista1.firstElement() );
            lista1.removeFirst();
        }
    }

    lista2.removeFirst();

}

template <class T> T Fifo  <T> ::getFirst(){
        assert(first == nullptr);

    return first;

}

// ======================================================================
//                            main
// ======================================================================
int main()
{
    Fifo <double> s;

    int K,L,M,N;
    double var;
    cin >> K;
    for(int i=0;i<K;i++) //dodawanie
    {
        cin >> var;
        s.push(var);
    }
    cin >> L;


    for(int i=0;i<L;i++) //odejmowanie
    {
        s.pop();
    }
    cin >> M;
    for(int i=0;i<M;i++) //dodawanie
    {
        cin >> var;
        s.push(var);
    }
    cin >> N;
    for(int i=0;i<L;i++) //odejmowanie
    {
        s.pop();
    }



    cout << s;
    //cout << s.getFirst();


    return 1;

}
