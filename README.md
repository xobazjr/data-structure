## Heap

#### Full code

```bash
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> heap);

int main(){
	vector<int> heap;
	
	heap.push_back(2);
	heap.push_back(5);
	heap.push_back(19);
	heap.push_back(50);
	heap.push_back(1);
	
	cout<<"Add (2,5,19,50,1)"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"before make_heap: ";
	print(heap); //output: 2 5 19 50 1
	
	cout<<"after make_heap: ";
	make_heap(heap.begin(),heap.end());
	print(heap); //output: 50 5 19 2 1
	cout<<"--------------------------------\n"<<endl;
	
	cout<<"Add (60)"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"before push_heap: ";
	heap.push_back(60);
	print(heap); //output: 50 5 19 2 1 60
	
	cout<<"after push_heap: ";
	push_heap(heap.begin(),heap.end());
	print(heap); //output: 60 5 50 2 1 19
	cout<<"--------------------------------\n"<<endl;
	
	cout<<"--------------------------------"<<endl;
	cout<<"pop_heap: ";
	pop_heap(heap.begin(),heap.end());
	print(heap); //output: 50 5 19 2 1 60
	
	cout<<"pop_back: ";
	heap.pop_back();
	print(heap); //output: 50 5 19 2 1
	cout<<"--------------------------------\n"<<endl;
	
	cout<<"--------------------------------"<<endl;
	cout<<"after make_heap: ";
	make_heap(heap.begin(),heap.end());
	print(heap); //output: 50 5 19 2 1
	cout<<"--------------------------------"<<endl;
	
	return 0;
}

void print(vector<int> heap){
	if(!heap.empty()){
		for(int i=0;i<heap.size();i++){
			cout<<heap[i]<<" ";
		}cout<<endl;
	}
}

```

#### Output

```bash
Add (2,5,19,50,1)
--------------------------------
before make_heap: 2 5 19 50 1
after make_heap: 50 5 19 2 1
--------------------------------

Add (60)
--------------------------------
before push_heap: 50 5 19 2 1 60
after push_heap: 60 5 50 2 1 19
--------------------------------

--------------------------------
pop_heap: 50 5 19 2 1 60
pop_back: 50 5 19 2 1
--------------------------------

--------------------------------
after make_heap: 50 5 19 2 1
--------------------------------
```
