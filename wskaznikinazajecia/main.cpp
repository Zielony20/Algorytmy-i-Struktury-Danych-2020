#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

class Okrag{

private:
    string name_;
    float radius_;

public:
    Okrag(){}
    Okrag( string name, float radius ):name_(name),radius_(radius){
        //cout << "create okrag"<<endl;
    }
    string getName(){
        return name_;
    }
    float getRadius()
    {
        return radius_;
    }
    float getCirciut(){
        return radius_*PI*2;
    }
    void display()
    {
        cout << getName()<<" "<<getCirciut();
    }

    bool operator > ( Okrag );

};
bool Okrag::operator > ( Okrag o ){
    if( this->getCirciut() > o.getCirciut() ) return 1;
    else return 0;
}
Okrag* makeOkrag(){
    string s;
    float r;
    do{
    cin >> s;
    }while( false ); // tu wstawić kontorlę błędów
    do{
        cin >> r;
    }while(!cin);

    Okrag* a= new Okrag(s,r);
    return a;
}
template <class T>
void Sortowanie( T tab[], int size )
{
    int k;
    for( int i = 0; i < size; i++ )
    {
        k = i;
        for( int j = i + 1; j < size; j++ )
        if( *(tab+j) > *(tab+k) )
             k = j;
        swap( tab[ k ], tab[ i ] );
    }
}

class Form{
    public:
    Form(){cout <<"cf"<<endl;}
    ~Form(){cout <<"cf"<<endl;}

    virtual float field()=0;
    virtual void display()=0;
    //virtual void create()=0;
};

class Wheel : public Form{
    private:
    string name_;
    float radius_;
    public:
    Wheel(){}
    ~Wheel(){}
    Wheel(string n,float radius):name_(n),radius_(radius){}
    float getRadius(){
        return radius_;
    }
    string getName(){
        return name_;
    }
    float field(){
       return getRadius()*getRadius()*PI;
    }
    void display(){
        cout<< getName() <<" "<< getRadius()<<endl;
    }
};
class Rectangle : public Form{
    private:
        string name_;
        float a_;
        float b_;
    public:
    Rectangle( string n , float a, float b):name_(n),a_(a),b_(b){}
    Rectangle(){cout<<"cr"<<endl;}
    ~Rectangle(){cout<<"cr"<<endl;}
    string getName(){
        return name_;
    }
    float getA(){
        return a_;
    }
    float getB(){
        return b_;
    }
    float field(){
       return getA()*getB();
    }
    void display(){
        cout<< getName() <<" "<< getA()<<" "<<getB()<<endl;
    }
};
int main()
{
    short int task;
    cin >> task;
    switch(task)
    {
        int size;
        case(1):
        {
            do{cin >> size;}while(!cin);
            Okrag* a = new Okrag[size];
            string s;
            float r;

        for(int i=0;i<size;i++)
        {
            do{
            cin >> s;
            }while( false );
            do{
                cin >> r;
            }while(!cin);
            a[i] = Okrag(s,r);
        }

        Sortowanie(a,size);

        for(int i=0;i<size;i++)
        {
            a[i].display();
            if(i!=size-1)cout<<" ";
            //cout << a[i]->getCirciut() <<endl;
        }



            break;
        }
        case(2):
        {
            int cols,rows;
            cin >> rows >> cols;
            string name;
            float d,b,radius;
            Form*** a=new Form**[rows];
            for(int i=0;i<rows;i++){
                a[i] = new Form*[cols];
            }

            for( int i=0;i<rows;i++ )
            {
                if( i%2 == 0 ){

                    for(int j=0;j<cols;j++)
                    {
                        cin >> name >> radius;
                        a[i][j] = new Wheel(name,radius);
                    }
                }

                 else{
                    for(int j=0;j<cols;j++)
                    {
                       cin >> name ;
                       cin>>d>>b;
                       a[i][j] = new Rectangle(name,d,b);
                    }
                }

            }
            int index1,index2;
            cin >> index1 >> index2;
            a[index1][index2]->display();

            break;
        }
    }

    return 1;
}








