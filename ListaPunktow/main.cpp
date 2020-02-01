#include<iostream>
#include <cassert>

using namespace std;

template <class T> class link;
template <class T> class Iterator;
class Point{
    private:
    string name_;
    double x_;
    double y_;
    public:
    Point(){}
    Point(string n,double x, double y):name_(n),x_(x),y_(y){}

    string getName(){return name_;}
    double getX(){return x_;}
    double getY(){return y_;}
    double getSumxy(){return x_ + y_;}

    bool operator ==(Point& s){
        if (s.getSumxy() == this->getSumxy()) return 1;
        else return 0;
    }
    friend class Iterator <Point>;
    friend class link <Point>;

   bool operator <( Point &p){
        if( this->getSumxy() < p.getSumxy() ) return 1;
        else return false;
    }

};

ostream& operator<<( ostream& s, Point& p ){
    return s<<p.getName()<<" "<<p.getX()<<" "<<p.getY();
}


// ======================================================================
//                    Class Template list
// ======================================================================
template <class T>
class list {
protected:
   link <T> *First;                // data field

public:
   list() : First(nullptr) {}      // default constructor
   list(const list &source);       // copy constructor
   virtual ~list() {};                // destructor

   virtual void add(T value);      // insert a new item
   virtual void delete_all();
   T first_element() const;        // access the first item
  // virtual bool includes(T value) const;  // inclusion test
   bool is_empty() const;
   virtual void remove_first();
   //void insert_sort (list<T> &v);
   friend class Iterator <T>;
};
// ======================================================================
//                    Class Template link
// ======================================================================
template <class T>
class link {
private:
   T Value;
   link <T> *Next;

   link(T val, link *ptr) : Value(val), Next(ptr) { }
public:
   link <T> *insert(T value);      // after current link

   friend class list <T>;
   friend class Iterator <T>;
};


// ======================================================================
//                    Class Template Iterator
// ======================================================================
template <class T> class Iterator {
public:
   Iterator(list <T> &aList);
   virtual bool init();
   virtual T operator()();
   virtual bool operator !();
   virtual bool operator++(); // for prefix, for postfix add dummy int
   virtual bool operator++(int);
   virtual void operator=(T value);
   void remove_current();
   void add_before(T new_value);
   void add_after(T new_value);
   friend class link <Point>;
protected:
   list <T> &my_list;             // data fields
   link <T> *previous;
   link <T> *current;
};

// ======================================================================
//                    Class Template link - attributes
// ======================================================================
template <class T> link <T> * link <T> :: insert(T value)
{
  Next = new link <T>(value, Next);
  return Next;
}

// ======================================================================
//                    Class Template list - attributes
// ======================================================================
template <class T> void list <T> :: add(T value)
{
   First = new link <T>(value, First);
}

template <class T> T list <T> :: first_element() const
{
   assert(First != nullptr);
   return First->Value;
}


template <class T> bool list <T> :: is_empty() const
{
   return First == nullptr;
}

/*
template <class T> bool list <T> :: includes(T value) const
{
   for (link <T> *p = First; p; p = p->Next)
       if (value == p->Value)return true;
   return false;
}
*/
template <class T> void list <T> :: remove_first() {
   assert(First != nullptr);
   link <T> *ptr = First;  // save pointer to the first item
   First = ptr->Next;      // reassign the First node
   delete ptr;
}

template <class T> void list <T> :: delete_all() {
   link <T> *next;
   for (link <T> *p = First; p; p = next){
       next = p->Next;
       delete p;
   }
   First = nullptr;
}

// ======================================================================
//                    Class Template Iterator - attributes
// ======================================================================
template <class T> Iterator <T> ::
   Iterator(list <T> &aList) : my_list(aList){
   init();
}
template <class T> bool Iterator <T> :: init(){
   previous = nullptr;
   current = my_list.First;
   return current != nullptr;
}
template <class T> T Iterator <T> :: operator()(){
   assert(current != nullptr);
   return current->Value;
}
template <class T> void Iterator <T> :: operator=(T val){
   assert(current != nullptr);
   current->Value = val;
}

template <class T> void Iterator <T> :: remove_current()
{
   assert(current != nullptr);
   if (previous == nullptr)
      my_list.First = current->Next;
   else
      previous->Next = current->Next;
   delete current;
   current = nullptr;
}

template <class T> bool Iterator <T> :: operator++(){
   if (current == nullptr){           // move current pointer
      if (previous == nullptr)        // to next element
         current = my_list.First;
      else
         current = previous->Next;
   }
   else {
      previous = current;
      current = current->Next;
   }
   return current != nullptr;
} // valid for prefix operator only!

template <class T> bool Iterator <T> :: operator++(int){
   if (current == nullptr){           // move current pointer
      if (previous == nullptr)        // to next element
         current = my_list.First;
      else
         current = previous->Next;
   }
   else {
      previous = current;
      current = current->Next;
   }
   return current != nullptr;
}

template <class T> bool Iterator <T> :: operator !(){
   if (current == nullptr and previous != nullptr)
      current = previous->Next;
   return current != nullptr;       // termination of iterator
}


template <class T> void Iterator <T> :: add_before(T val)
{
   if (previous)previous = previous->insert(val);
   else {
      my_list.list<T>::add(val);     // to avoid subclass
      previous = my_list.First;
      current = previous->Next;      // if current is NULL
   }
}

template <class T> void Iterator <T> :: add_after(T val)
{
   if (current){current->insert(val); return;}  // not shown
   if (previous)current = previous->insert(val);
   else my_list.list<T>::add(val);
}


template <class T> class ordered_list : public list<T>{
  public:
    virtual void add (T value);
};
template <class T> void ordered_list <T> :: add (T value) {
    Iterator <T> itr(*this);
    for(itr.init(); !itr ; ++itr){
        if(value < itr()){
            itr.add_before(value);
            return;
        }
    }
    itr.add_before(value);
}



template <class T> void insert_sort (T arr[],int n){ //list?

    {
        T key;
        int i, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

}

int main() {
    list<Point> lista;
    Iterator<Point> greatIterator(lista);
    int n;
    string name;
    float x,y;
    cin >> n;
    Point* p= new Point[n];
    for(int i=0;i<n;i++)
    {
        cin >> name >> x >> y;
        p[i] = Point(name,x,y);
    }
    insert_sort(p,n);
    for(int i=0;i<n;i++) lista.add(p[i]);
    Point temp;

    int toDelete;
    cin >> toDelete;
    for(greatIterator.init();!greatIterator;greatIterator++)
    {
        temp = greatIterator();
        if( temp.getSumxy() == toDelete )
        greatIterator.remove_current();
        else continue;
    }
    for(greatIterator.init();!greatIterator;greatIterator++)
    {
       temp = ( greatIterator() );
       cout << temp;
       if( !greatIterator ) cout << " ";
    }

    delete [] p;
    return 1;
}

