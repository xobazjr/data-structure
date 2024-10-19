#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class max_heap{
	public:
		vector<int> heap;
	
	void heapify_up(){
		make_heap(heap.begin(),heap.end());
	}
	
	void heapify_down(int index){
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int largest = index;
		
		if(left < heap.size() && heap[left] > heap[largest]){
			largest = left;
		}
		if(right < heap.size() && heap[right] > heap[largest]){
			largest = right;
		}
		if(largest != index){
			swap(heap[index],heap[largest]);
			heapify_down(largest);
		}
		 
	}
	
	void add(int data){
		heap.push_back(data);
		heapify_up();
	}
	
	void remove(){
		if(!heap.empty()){
			int remove_data = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			cout<<remove_data<<endl;
			heapify_down(0);
		}
	}
	
	void print(){
		if(!heap.empty()){
			for(int i=0;i<heap.size();i++){
				cout<<heap[i]<<" ";
			}cout<<endl;
		}
	}
};

int main(){
	max_heap heap;
	char cmp;
	int data;
	
	do{
		cin>>cmp;
		if(cmp == 'a'){
			cin>>data;
			heap.add(data);
		}else if(cmp == 'p'){
			heap.print();
		}else if(cmp == 'd'){
			heap.remove();
		}
	}while(cmp != 'e');
	
	return 0;
}
