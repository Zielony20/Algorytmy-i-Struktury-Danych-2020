#include<iostream>
#include <string>
using namespace std;

class Car{
    public:

        string number_; // 4 znaki
        int power_;
        double weight_;
        char engineType_; // B D E H

    Car()
    {
        //cout << "create car" <<endl;
    }

    Car(string nr, int p, double w, char eT):number_(nr), power_(p),weight_(w),engineType_(eT)
    {
        //cout << "Creating a car with data" <<endl;
    }

    ~Car(){
        //cout << "destroy car"<<endl;
    }

    int getPower(){
        return power_;
    }

    string getNumber(){
        return    number_;
    }

    double getWeight(){
        return weight_;
    }

    char getEngineType(){
        return engineType_;
    }


};
class Catalog{

        int counter_;
        static const int size_ = 10;
        int heapSize_ = 0;
    public:

        
        Car catalogCar_[size_];
        Car vector_[size_];
        Catalog() {
            counter_ = 0;
            //cout << "Creating a catalog of cars." <<endl;
        }
        ~Catalog(){
            //cout << "destroy catalog" << endl;
        }
        void heapInsert( Car toAdd ){
            int child = ++heapSize_;
            int parent = child/2;

            while( parent and (catalogCar_[parent].getPower() > toAdd.getPower() ))
                {
                    catalogCar_[child] = catalogCar_[parent];
                    child = parent;
                    parent /= 2;
                }
                catalogCar_[child] = toAdd;
        }
        void heapRemoveMinCar(){

            Car last = catalogCar_[heapSize_--];
            int x = 1;
            int c = heapMinCar(x);

            while(c and catalogCar_[c].getPower()<last.getPower()){

                catalogCar_[x] = catalogCar_[c];
                x=c;
                c=heapMinCar(c);
            }
            catalogCar_[x]=last;
        }
        int heapMinCar( int parent ){
            int left = 2 * parent;
            int right = left + 1;
            if( left > heapSize_ )
            {
                return 0;
            }
            if( right > heapSize_ or catalogCar_[left].getPower()<catalogCar_[right].getPower() )
            {
                return left;
            }
            return right;
        }

        void heapsort(){
            Car catalogCarTemp_[size_];
            int tempHeapSize = heapSize_;
            for(int i=0;i<heapSize_+1;i++)
            {
                catalogCarTemp_[i]=catalogCar_[i];
            }

            for(int i=0;i<tempHeapSize;i++)
            {
                vector_[i] = catalogCar_[1];
                heapRemoveMinCar();
            }

            heapSize_=tempHeapSize;
        }
        void displayCatalogSorted()
        {
            for(int i=0;i<heapSize_;i++)
            {
                if(i!=0) cout<<" ";
                cout << vector_[i].getNumber()<<" ";
                cout << vector_[i].getPower();
            }
        }

};
string giveNum(){
    string num;
    do{
        getline(cin,num,' ');
    }while(num.length()>4);
    return num;
}
char giveType(){
    char type;
    string data;
    do{
        cin >> type;
    }while(  (type!='B' and type!='D' and type!='E' and type!='H') );
    return type;
}
void carAttributs(string &num, int &power, double &w, char &t)
{
    num = giveNum();
    do{
    cin>>power;
    }while(!cin);
    do{
    cin>>w;
    }while(!cin);
    t = giveType();
}

int main()
{
    string num;
    int p;
    double w;
    char t;
    Catalog myCatalog;
    Car *cars[6];
    string cleaner;
        for (int a = 0; a<6; a++) {

            carAttributs(num,p,w,t);
            cars[a] = new Car(num,p,w,t);
            myCatalog.heapInsert(*cars[a]);
            if(a<5) getline(cin,cleaner,' ');
        }

    myCatalog.heapsort();
    myCatalog.displayCatalogSorted();

    for (int a = 0; a<6; a++)
        delete cars[a];

    return 0;
}

