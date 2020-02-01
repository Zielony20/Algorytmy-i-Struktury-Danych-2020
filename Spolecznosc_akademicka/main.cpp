#include<iostream>

using namespace std;

enum gender{K,M};

class Person{
    private:
        string name_;
        string surname_;
        float weight_;
        float height_;
        int age_;
    protected:
        gender s_;
    public:
    Person(){}
    Person(string n, string sn, float w, float h, int a, gender s)
    :name_(n), surname_(sn),weight_(w),height_(h),age_(a), s_(s)
    {
        //cout << "Born a PErSoN!!!"<<endl;
    }
    float bmi(){
        return weight_/(height_*height_/10000);
    }
    void display()
    {
        cout<<getName()<<" "<<getSurname()<<" "<<getWeight()<<" "<<getHeight()<<" "<<getAge()<<" "<<getGender()<<endl;
    }
    string getName(){
        return name_;
    }
    string getSurname(){
        return surname_;
    }
    float getWeight(){
        return weight_;
    }
    float getHeight(){
        return height_;
    }
    int getAge(){
        return age_;
    }
    gender getGender()
    {
        return s_;
    }



};

class Student : public Person{

private:
    string index_;
    int year_;
public:
    double grades_[10];
    Student(){}
    Student(string name, string surname, float weight, float height, int age, gender s, string i,int y, double g1,double g2,double g3,double g4,double g5 ):
       Person(name,surname,weight,height,age,s) ,index_(i), year_(y){

        grades_[0]=g1;
        grades_[1]=g2;
        grades_[2]=g3;
        grades_[3]=g4;
        grades_[4]=g5;
    }

    int getYear(){
        return year_;
    }
    string getIndex(){
        return index_;
    }

    double average(){

        double result=0;
        int s=5;
            for(int i=0;i<s;i++)
            {
                result += grades_[i];
            }
        return result/s;
    }

};

class Worker : public Person{
    /*atrybuty prywatne opisujące: nazwę firmy, w której pracownik pracuje (typ string), zajmowane stanowisko (typ string), wynagrodzenie w PLN (typ float), oraz staż pracy w latach (typ float).
konstruktor inicjalizujący powyższe atrybuty w zadanej wyżej kolejności.
metodę obliczającą lata pozostałe do emerytury zakładając wiek emerytalny 60 i 65 lat odpowiednio dla kobiet i mężczyzn.*/


private:
    string firmName_;
    string position_;
    float salary_;
    float seniority_;

public:
    Worker(string name, string surname, float weight, float height, int age, gender s,  string n, string p, float sa, float se ):Person(name,surname,weight,height,age,s), firmName_(n),position_(p),salary_(sa),seniority_(se){
        //cout<<"Mamy Pracownika!!!"<<endl;
    }

    double whenPension(){

    if( this->Person::getGender() == K )
        return 60-Person::getAge();

    else if(this->Person::getGender() == M)
        return 65-Person::getAge();

    }


};


class Course{
    private:
        string courseName_;
        Student studenci_[5][10];
        int studentsOnYears[5]={0};
        int y1,y2,y3,y4,y5=0;
    public:
    Course(string n):
    courseName_(n){
        //cout << "Create a Course";
    }


    bool addToList(Student toAdd){

    int n = toAdd.getYear();
    if( studentsOnYears[ toAdd.getYear()-1 ] < 10 )
    {
        studenci_[toAdd.getYear()-1][ studentsOnYears[ toAdd.getYear()-1 ] ] = toAdd;
        studentsOnYears[ toAdd.getYear()-1 ]++;
        return true;
    }
    else{
        return false;
    }
    }

    void displayStudents()
    {
        for(int j=0;j<5;j++){
            cout <<j+1<<":";
        for(int i = 0;i<studentsOnYears[j];i++)
            cout << studenci_[j][i].getSurname() << " "<<studenci_[j][i].average()<<" ";
        cout << endl;
        }
    }


    void sort(int year)
    {
        year = year-1;
        int j;
        Student pom;


             for(int i=1; i<studentsOnYears[year]; i++)
             {
                     //wstawienie elementu w odpowiednie miejsce
                     pom = studenci_[year][i]; //ten element będzie wstawiony w odpowiednie miejsce
                     j = i-1;

                     //przesuwanie elementów większych od pom
                     while(j>=0 && studenci_[year][j].average()<pom.average())
                     {
                                studenci_[year][j+1] = studenci_[year][j]; //przesuwanie elementów
                                --j;
                     }
                     studenci_[year][j+1] = pom; //wstawienie pom w odpowiednie miejsce
             }
             //displayStudents();

    }
    void displayBest3(int year){

        sort(year);

        if( studentsOnYears[year-1] >= 1 )cout<<studenci_[year-1][0].getIndex()<<" "<<studenci_[year-1][0].getName()<<" "<<studenci_[year-1][0].getSurname();

        if( studentsOnYears[year-1] >= 2 )cout<<" "<<studenci_[year-1][1].getIndex()<<" "<<studenci_[year-1][1].getName()<<" "<<studenci_[year-1][1].getSurname();

        if( studentsOnYears[year-1] >= 3 )cout<<" "<<studenci_[year-1][2].getIndex()<<" "<<studenci_[year-1][2].getName()<<" "<<studenci_[year-1][2].getSurname();

    }

};



int main()
{
    string name, surname, index, firmName, position;
    float height, weight, salary, staz;
    int age, year;
    double g[5];
    gender se;
    char gender;
    Student *s[10];

    cin >> name;
    Course k(name);

    for(int i=0;i<10;i++){

        cin >> name >> surname >> height >> weight >> age >> gender  >> index >> year;
        if(gender=='M') se = M;
        else se=K;
        for(int j=0;j<5;j++) cin>>g[j];

        s[i]=new Student(name,surname,height,weight,age,se,index,year,g[0],g[1],g[2],g[3],g[4]);
        k.addToList(*s[i]);
    }
    cin >> year;

    cin >> name >> surname >> height >> weight>> age >> gender >> firmName >> position >> salary >> staz;
    if(gender == 'M') se = M;
    else se = K;
    Worker a(name,surname,height,weight,age,se,firmName,position,salary,staz);

    cin >> name >> surname >> height >> weight>> age >> gender >> firmName >> position >> salary >> staz;
    if(gender == 'M') se = M;
    else se = K;
    Worker b(name,surname,height,weight,age,se,firmName,position,salary,staz);

    //k.displayStudents();
    k.displayBest3(year);
    cout<<" "<<a.whenPension()<<" ";
    cout<<b.whenPension();

    return 0;
}
