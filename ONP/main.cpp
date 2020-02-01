#include <iostream>
#include <cassert>

using namespace std;


template <class T> class link;

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
   virtual bool includes(T value) const;  // inclusion test
   bool is_empty() const;
   virtual void remove_first();


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


template <class T> bool list <T> :: includes(T value) const
{
   for (link <T> *p = First; p; p = p->Next)
       if (value == p->Value)return true;
   return false;
}

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

float toMyFloat(char f){
    float op=0;
    switch(f){
        case  '2': op=2; break;
        case  '3': op=3; break;
        case  '4': op=4; break;
        case  '5': op=5; break;
        case  '6': op=6; break;
        case  '7':op=7; break;
        case  '8':op=8; break;
        case  '9':op=9; break;
        case  '1':op=1; break;
        case  '0':op=0; break;

    }
    return op;
}


// ======================================================================
//                            main
// ======================================================================
int main()
{

    string input;
    list<float> lista;
    getline(cin,input);
    InputONP* a;
    int j=0;
    float tempA,tempB;
    for(int i=0;i<input.length();i++)
    {



        switch (input[i]){
        case ' ': break;
        case '+': {
            tempA = lista.first_element();
            lista.remove_first();
            tempB = lista.first_element();
            lista.remove_first();
            lista.add(tempA+tempB);
        }break;
        case '-': {
            tempA = lista.first_element();
            lista.remove_first();
            tempB = lista.first_element();
            lista.remove_first();
            lista.add(tempB-tempA);
        }break;
        case '/': {
            tempA = lista.first_element();
            lista.remove_first();
            tempB = lista.first_element();
            lista.remove_first();
            lista.add(tempB/tempA);
        }break;
        case '*': {
            tempA = lista.first_element();
            lista.remove_first();
            tempB = lista.first_element();
            lista.remove_first();
            lista.add(tempA*tempB);
        }break;
        default:{
            float mantisse=0;
            float value=0;
            int k=10; // krotność
            int v=1; // lewa strona włączona
            float m=0; // prawa strona wyłączona
            while( input[i]!=' ' )
            {

                if(input[i]=='.'){
                    v=0;
                    m=0.1;
                    k=1;
                    i++;
                    continue;
                }

                value = value * k + v * toMyFloat(input[i]) ;
                mantisse = mantisse + toMyFloat(input[i]) * m ;
                m /= 10;
                i++;
            }
            value += mantisse;
            lista.add( value );

        }//endOfDefault
        }
    }

    cout << lista.first_element() <<endl;



    return 1;
}
