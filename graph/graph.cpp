#include <iostream>
#include <vector>
using namespace std;

class graph{
	public:
		int s_v; //vertex
		vector<vector<int> > edges;
		
		graph(int n){
			s_v = n;
			edges = vector<vector<int> >(s_v,vector<int>(s_v,0));
		}
		
	void addedge(int x,int y,int w){
		edges[x][y] = w;
	}
		
	void print(){
		if(!edges.empty()){
			for(int i=0;i<s_v;i++){
				cout<<i<<" : ";
				for(int j=0;j<s_v;j++){
					cout<<edges[i][j]<<" ";	
				}cout<<endl;
			}
		}
	}
		
	bool visited_dft[100];
	bool visited_bft[100];
		
	void sub_dft(int start){
		cout<<start<<" ";
		visited_dft[start] = 1;
		for(int i=0;i<s_v;i++){
			if(visited_dft[i] == 0 && edges[start][i] > 0){
				sub_dft(i);
			}
		}
	}
		
	void dft(int start){
		for(int i=0;i<100;i++){
			visited_dft[i] = 0;
		}
		sub_dft(start);
		cout<<endl;
	}
		
	void sub_bft(int start){
		visited_bft[start] = 1;
		vector<int> q;
		q.push_back(start);
		while(q.empty() == 0){
			start = q.front();
			cout<<start<<" ";
			q.erase(q.begin());
			for(int i=0;i<s_v;i++){
				if(visited_bft[i] == 0 && edges[start][i] > 0){
					visited_bft[i] = 1;
					q.push_back(i);
				}
			}
		}
	}
	
	void bft(int start){
		for(int i=0;i<100;i++){
			visited_bft[i] = 0;
		}
		sub_bft(start);
		cout<<endl;
	}
};

int main(){
	int n,x,y,w,start;
	char cmp;
	cin>>n;
	graph g(n);
	
	do{
		cin>>cmp;
		if(cmp == 'e'){
			cin>>x>>y>>w;
			g.addedge(x,y,w);
		}else if(cmp == 's'){
			while(true){
				cin>>cmp;
				if(cmp == 'd'){
					cin>>start;
					g.dft(start);
				}else if(cmp == 'b'){
					cin>>start;
					g.bft(start);
				}else if(cmp == 'q'){
					return 0;
				}
			}
		}
	}while(cmp != 'q');

	return 0;
}
