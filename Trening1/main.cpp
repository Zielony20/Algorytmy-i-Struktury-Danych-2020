#include <iostream>

using namespace std;


class A{

    private:
    int a_;
    float b_;
    public:
    A(int a,float b ):a_(a),b_(b){

    }
    A(){}

    void operator+=(A toAdd){

       A temp;

       this->a_ += toAdd.a_;
       this->b_ += toAdd.b_;
    }
            int getA(){return a_;}
            float getB(){return b_;}
           void display(){cout << getA()<<" "<<getB()<<endl;}

           ostream& operator<<(ostream& s,const A a){

               return s<<this->getA()<<" "<<this->getB();

           }

};



int main(){

    A a(2, 3.4);
    A aa(3,4.5);
    a+=aa;
    //a.display();
    cout << a;
    cout << aa;
    return 0;
}
