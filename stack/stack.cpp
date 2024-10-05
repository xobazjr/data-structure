#include <iostream>
#include <vector>
using namespace std;

class stack{
    public:
        vector <int> array;

    void add(int data){
        array.push_back(data);
    }

    void pop(){
        if(!array.empty()){
            cout<<array[array.size()-1]<<endl;
            array.pop_back();
        }
    }

    void top(){
        if(!array.empty()){
            cout<<array[array.size()-1]<<endl;
        }
    }

    void print(){
        if(!array.empty()){
            for(int i=0;i<array.size();i++){
                cout<<array[i]<<" ";
            }cout<<endl;
        }
    }

    int size(){
        return array.size();
    }

};

int main(){
    stack s;
    char cmp;
    int data;

    do{
        cin>>cmp;
        if(cmp == 'U'){
            cin>>data;
            s.add(data);
        }else if(cmp == 'O'){
            s.pop();
        }else if(cmp == 'T'){
            s.top();
        }else if(cmp == 'P'){
            s.print();
        }else if(cmp == 'N'){
            cout<<s.size()<<endl;
        }
    }while(cmp != 'X');
}