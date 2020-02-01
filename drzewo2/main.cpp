#include <iostream>

using namespace std;

template <class T>class Tree;

template <class T>
class Leaf{

  public:
  T value;

  //protected:
  Leaf<T>* left;
  Leaf<T>* right;

  //public:
  Leaf(){}
  Leaf(T v):value(v){
      left = nullptr;
      right = nullptr;
  }
  friend class Tree<T>;
};

template <class T>
class Tree{

  T* firstElement;

  public:
  Tree():firstElement(nullptr){}

  T* getFirst(){
      return firstElement;
  }
  void AddToTree(T *element){
      cout << "Add";
      if(firstElement==nullptr){
          firstElement=element;
          return;
      }
      T** top = &firstElement;
      while(*top != nullptr)
      {
          if( (*top)->value > element->value )
              top = &(*top)->left;
          else
              top = &(*top)->right;
      }
      *top = element;

  }
  void DeleteFromTree(double value){

  }
  int showLongestWay(){
      return 0;
  }
  int showShortestWay(){
      return 0;
  }
  void DisplayByInOrder(T *ptr){
      if(ptr) {
          DisplayByInOrder(ptr->left);
          cout<<ptr->value<<" ";
          DisplayByInOrder(ptr->right);


      }
  }
  void DisplayByPreOrder(T *ptr){
      if (ptr) {
          cout << ptr->value << " ";
          DisplayByPreOrder(ptr->left);
          DisplayByPreOrder(ptr->right);
      }
  }
  void DisplayByPostOrder(T *ptr){
      if (ptr) {
          DisplayByPostOrder(ptr->left);
          DisplayByPostOrder(ptr->right);
          cout << ptr->value << " ";
      }
  }

};

ostream& operator <<(ostream& s, Leaf<double> toDisplay){
    s << toDisplay.value;
    return s;
}

int main()
{

    Tree<Leaf<double>> t;
    int K;
    cout << "Enter number of nodes: ";
    cin >> K;
    //Leaf<double>* l = new Leaf<double> [K];
    Leaf<double>* temp;
    double value;
    for(int i = 0;i<K;i++)
    {
        cout << "Enter node (" << i << ") :";
        cin >> value;
       //l[i] = Leaf<double>(value);
       temp = new Leaf<double>(value);
        t.AddToTree( temp );
    }

    int L;
    cout << "Enter number of nodes to remove : ";
    cin >> L;
    for(int i = 0;i<L;i++)
    {
        cout << "Node with value to remove : ";
        cin >> value;
        t.DeleteFromTree(value);
    }

    int M;
    cout << "Display mode : ";
    cin >> M;

    switch(M){
    case 0:t.DisplayByPreOrder(t.getFirst()); break;
    case 1:t.DisplayByInOrder(t.getFirst()); break;
    case 2:t.DisplayByPreOrder(t.getFirst()); break;
    }

    //delete [] l;



    return 1;
}



