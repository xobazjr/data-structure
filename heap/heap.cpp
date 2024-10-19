#include <iostream>
#include <vector>
using namespace std;

class max_heap{
	public:
		vector<int> heap;
		
	void heapify_up(int index){
		if(index && heap[parent(index)] < heap[index]){
			swap(heap[index],heap[parent(index)]);
			heapify_up(parent(index));
		}
	}
	
	void heapify_down(int index){
		int left = left_child(index);
		int right = right_child(index);
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
		heapify_up(heap.size() - 1);
	}
	
	void remove(){
		if(!heap.empty()){
			int remove_data = heap[0];
			heap[0] = heap.back();
			heap.pop_back();
			heapify_down(0);
			cout<<remove_data<<endl;
		}
	}
	
	int print(){
		if(!heap.empty()){
			for(int i=0;i<heap.size();i++){
				cout<<heap[i]<<" ";
			}cout<<endl;
		}
	}
	
	int parent(int index){
		return (index - 1) / 2;
	}
	
	int left_child(int index){
		return 2 * index + 1;
	}
	
	int right_child(int index){
		return 2 * index + 2;
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
