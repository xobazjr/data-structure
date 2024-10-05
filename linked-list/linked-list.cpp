#include <iostream>
#include <list>
using namespace std;

class LinkedList{
  public:
    list <int> link;

  bool duplicate(int id){
    if(!link.empty()){
      list <int>::iterator tpr = link.begin();
      for(int i=0;i<link.size();i++,tpr++){
        if(*tpr == id){
          return 1;
        }
      }
    }return 0;
  }
  
  void before(int n,int id){
    if(!link.empty() && duplicate(id) && !duplicate(n)){
      list <int>::iterator tpr = link.begin();
      for(int i=0;i<link.size();i++,tpr++){
        if(*tpr == id){
          list <int>::iterator tpr = link.begin();
          advance(tpr,i);
          link.insert(tpr,n);
          print();
          break;
        }
      }
    }else if(!duplicate(n)){
      link.push_back(n);
      print();
    }
  }

  void after(int n,int id){
    if(!link.empty() && duplicate(id) && !duplicate(n)){
      list <int>::iterator tpr = link.begin();
      for(int i=0;i<link.size();i++,tpr++){
        if(*tpr == id){
          list <int>::iterator tpr = link.begin();
          advance(tpr,i+1);
          link.insert(tpr,n);
          print();
          break;
        }
      }
    }else if(!duplicate(n)){
      link.push_back(n);
      print();
    }
  }

  void dequeue(int id){
    if(!link.empty() && duplicate(id)){
      list <int>::iterator tpr = link.begin();
      for(int i=0;i<link.size();i++,tpr++){
        if(*tpr == id){
          list <int>::iterator tpr = link.begin();
          advance(tpr,i);
          link.erase(tpr);
          print();
          break;
        }
      }
    }
  }

  void print(){
    if(!link.empty()){
      list <int>::iterator tpr = link.begin();
      for(int i=0;i<link.size();i++,tpr++){
        cout<<*tpr<<" ";
      }cout<<endl;
    }
  }
};

int main(){
  LinkedList l;
  char cmp;
  int n,id;
  
  do{
    cin>>cmp;
    if(cmp == 'I'){
      cin>>n>>id;
      l.before(n,id);
    }else if(cmp == 'A'){
      cin>>n>>id;
      l.after(n,id);
    }else if(cmp == 'D'){
      cin>>id;
      l.dequeue(id);
    }
  }while(cmp != 'E');
  
  return 0;
}
