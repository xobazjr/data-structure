#include<iostream>

using namespace std;

class heap {
	public:
    	int q[1000];  
    	
    	heap() {
        	q[0] = 0;  
    	}
    
    void insert(int n) {
        if (q[0] < 999) {  
            q[0] = q[0] + 1;  
            q[q[0]] = n;  
            int i = q[0];
   
            while (i > 1 && q[i/2] < q[i]) {
                int t = q[i/2];
                q[i/2] = q[i];
                q[i] = t;
                i = i/2;  
            }
        }
    }

    int Delete(){
        if(q[0] > 0){
            int maxVal = q[1];
            q[1] = q[q[0]]; 
            q[0]--;  

            int p = 1;
            while (p <= q[0]) {
                int l = p*2;
                int r = (p*2) + 1;
                int largest = p;

                if (l <= q[0] && q[l] > q[largest]) {
                    largest = l;
                }
                if (r <= q[0] && q[r] > q[largest]) {
                    largest = r;
                }
                if (largest != p) {
                    int t = q[largest];
                    q[largest] = q[p];
                    q[p] = t;
                    p = largest;
                } else {
                    break;
                }
            }
            cout<<maxVal<<endl;
            return maxVal;
        }return -1;  
    }

    void print() {
    	if(q[0] > 0){
    		for(int i = 1; i <= q[0]; i++){
            	cout<<q[i]<< " ";
        	}cout<<endl;
				}
    }
};

int main() {
    heap h;
    char cmp;
    int n;
    do{
    	cin>>cmp;
		if(cmp =='a'){
			cin>>n;
			h.insert(n);
		}else if(cmp =='p'){
			h.print();
		}else if(cmp =='d'){
			h.Delete();
		}
		else{
			return 0;
		}
	}while(cmp != 'e');
}
