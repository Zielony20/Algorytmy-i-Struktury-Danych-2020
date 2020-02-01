#include<iostream>

using namespace std;

template <class Item> class Box{
  int counter_=0;
  const int MAX_=6;
  friend void AnimalSort(Box <Item>*,int);
public:
    Item array[6];
    bool addToBox( Item toAdd ){
        if(counter_>5) return false;
        else{
            array[counter_] = toAdd;
            counter_++;
            return true;
        }
    }
    bool removeFromBox(int index){
        //index--;

        if( (index > 6) or (index < 0) or (index > counter_) ) return false;
        else{
            array[index] = array[--counter_];
            //usun ostatni jeszcze
            return true;
        }

    }
    void displayBox()
    {
        for(int i=0;i<counter_;i++)
        {
            array[i].display();
            if(i<counter_-1)cout<<" ";
        }
    }

    int getCounter(){
        return counter_;
    }

};


class Building{
    string name_;
    float x_;
    float y_;
    float height_;
    friend void AnimalSort(Box <Building>*,int);
public:
    Building(){}
    Building(string name,float x, float y, float h):name_(name),x_(x),y_(y),height_(h){
        //cout << "Powstał BuuuuudyyyyNek" << endl;
    }
    string getName(){
        return name_;
    }
    float getX(){
        return x_;
    }
    float getY(){
        return y_;
    }
    float getHeight(){
        return height_;
    }
    void display(){
       cout << getName() <<" "<< getX() <<" "<< getY() <<" "<< getHeight();
   }

    bool operator >(Building b){
        if(this->getX()+this->getY() < b.getX()+b.getY()) return true;
        else return false;
    }

};

class Animal{
   string name_;
   float weight_;
   int bornYear_;
   string id_;
   friend void AnimalSort(Box <Animal>*,int);
public:
   Animal(){}
    Animal(string ,float, int, string);

    string getName(){
        return name_;
    }
    float getWeight(){
        return weight_;
    }
   int getBornYear(){
       return bornYear_;
   }
   string getId(){
       return id_;
   }
   void display(){
       cout << getName() <<" "<< getWeight() <<" "<< getBornYear() <<" "<< getId();
   }

   bool operator >(Animal b){

       if(this->getBornYear() > b.getBornYear()) return true;
       else if( this->getBornYear() == b.getBornYear() ){
           if( this->getWeight() < b.getWeight() ) return true;
       }
       else return false;
   }

} ;
Animal::Animal(string n,float w, int by, string id):
name_(n),weight_(w),bornYear_(by),id_(id){
    //cout <<"Mamy Zwierza!! YEAH!!"<<endl;
}

void AnimalSort(Box <Animal>& box,int n)
{
    int pmin,j,i;
    for(j = 0; j < n - 1; j++)
      {
        pmin = j;
        for(i = j + 1; i < n; i++)
          if(box.array[i] > box.array[pmin]) pmin = i;
        swap(box.array[pmin], box.array[j]);
      }
}

void BuildSort(Box <Building>& box,int n)
{
    int pmin,j,i;
    for(j = 0; j < n - 1; j++)
      {
        pmin = j;
        for(i = j + 1; i < n; i++)
          if(box.array[i] > box.array[pmin]) pmin = i;

        swap(box.array[pmin], box.array[j]);
      }
}

template <class myType>
void sort(Box <myType>& box,int n){

    int pmin,j,i;
    for(j = 0; j < n - 1; j++)
      {
        pmin = j;
        for(i = j + 1; i < n; i++)
          if(box.array[i] > box.array[pmin]) pmin = i;

        swap(box.array[pmin], box.array[j]);
      }

}

int main()
{
//Ado 5 1999 z1 Bedo 10 2010 z2 Cedo 15 2015 z3 Dedo 8 2013 z4
    Box <Animal> animalBox;
    Box <Building> buildingsBox;
    string name,id;
    int year,index;
    float w,h,x,y;
    Animal *a[4];
    for(int i=0;i<4;i++) {
        do{
        cin >> name;
        cin >> w;
        }while(!cin);
        do{cin>>year;}while(!cin);
        cin>> id;
        a[i] = new Animal(name,w,year,id);
        animalBox.addToBox(*a[i]);
    }
    Building *b[4];
    for(int i=0;i<4;i++) {
        do{
        cin >> name;
        cin >> x;
        }while(!cin);
        do{cin >> y;}while(!cin);
        do{cin >> h;}while(!cin);
        b[i] = new Building(name,x,y,h);
        buildingsBox.addToBox(*b[i]);
    }
    cin >> index;
    animalBox.removeFromBox(index);
    sort(animalBox,animalBox.getCounter());
    sort(buildingsBox,buildingsBox.getCounter());
    animalBox.displayBox();
    cout <<" ";
    buildingsBox.displayBox();
    for(int i=0;i<4;i++) {
        delete b[i];
        delete a[i];
    }
    return 0;
}
