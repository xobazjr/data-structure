#include <iostream>
#include <list>
using namespace std;

class queue{
	public:
		list <int> array;
		
	void add(int data){
		array.push_back(data);
	}
	
	void dequeue(){
		if(!array.empty()){
			cout<<array.front()<<endl;
			array.pop_front();
		}
	}
	
	void print(){
		if(!array.empty()){
			list <int>::iterator tpr = array.begin();
			for(int i=0;i<array.size();i++,tpr++){
				cout<<*tpr<<" ";
			}cout<<endl;
		}
	}
	
	void size(){
		cout<<array.size()<<endl;
	}
	
	void show_first_and_last(){
		cout<<array.front()<<" "<<array.back()<<endl;
	} 
};

int main(){
	queue q;
	char cmp;
	int data;
	
	do{
		cin>>cmp;
		if(cmp == 'e'){
			cin>>data;
			q.add(data);
		}else if(cmp == 'd'){
			q.dequeue();
		}else if(cmp == 'p'){
			q.print();
		}else if(cmp == 'n'){
			q.size();
		}else if(cmp == 's'){
			q.show_first_and_last();
		}
	}while(cmp != 'x');
	
	return 0;
}
