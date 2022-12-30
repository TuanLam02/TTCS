#include <fstream>
#include <iostream>
#define maxn 100
using namespace std;
class ShortestPath{
	private:
		int matrix[maxn][maxn];
		int num_vertex;
		int num_distance;
		int start;
		int w[maxn],trace[maxn],check[maxn];
	public:
		void Create(){
			cin>>num_vertex;
			cin>>num_distance;
			for(int i=1;i<=num_vertex;i++){
				for(int j=1;j<=num_vertex;j++){
					if(i!=j){
						matrix[i][j]=INT_MAX;
					}
					else{
						matrix[i][j]=0;
					}
				}
			}
			for(int i=1;i<=num_distance;i++){
				int u,v;
				cin>>u>>v;
				cin>>matrix[u][v];
			}
		}
		void Dijkstra(){
			cin>>start;
			for(int i=1;i<=num_vertex;i++){
				for(int j=1;j<=num_vertex;j++){
					matrix[j][i]=matrix[i][j];
				}
			}
			for(int i=1;i<=num_vertex;i++){
				check[i]=true;
				w[i]=INT_MAX;
			}
			trace[maxn]=start;
			int r=start,index;
			w[r]=0;
			int k=0;
			while(k<=num_vertex){
				if(r!=k){
					index=INT_MAX;
					for(int j=1;j<=num_vertex;j++){
						if( check[j]==true && index>w[j] ){
							index=w[j];
							r=j;
						}
					}

					check[r]=false;
					for(int j=1;j<=num_vertex;j++){
						if(matrix[r][j]!=INT_MAX&&w[j]>w[r]+matrix[r][j]){
							w[j]=w[r]+matrix[r][j];
							trace[j]=r;
						}
					}
				}
				k++;
			}
		}
		void Bellmanford(){
			cin>>start;
			for(int i=1;i<=num_vertex;i++){
				check[i]=true;
				w[i]=INT_MAX;
			}
			int r=start,index;
			trace[num_vertex]=0;
			w[r]=0;
			int i=1;
			while(i<=num_vertex){
					index=INT_MAX;
					for(int j=1;j<=num_vertex;j++){
						if(check[j]==true&&index>w[j]){
							index=w[j];
							r=j;
						}
					}
					check[r]=false;
					for(int j=1;j<=num_vertex;j++){
						if(matrix[r][j]!=INT_MAX && w[j]>w[r]+matrix[r][j]){
							w[j] = w[r] + matrix[r][j];
							trace[j]=r;
						}
				}
				i++;
			}
		}
		void Output(){
			for(int i=1;i<=num_vertex;i++){
				if(start==i || w[i]==INT_MAX){
					cout<<"KHONG CO DUONG DI";
					cout<<endl;
					cout<<endl;
				}
				else{
					cout<<"TRONG SO DI DEN "<<i<<" LA: "<<w[i]<<endl;
					cout<<"DUONG DI DEN "<<i<<" LA: ";
					int path[maxn],d=1;
					int k=i;
					path[d]=k;
					while(trace[k]!=0){
						k=trace[k];
						d++;
						path[d]=k;
					}
					for(int j=d;j>0;j--){
						cout<<path[j]<<" ";
					}
					cout<<endl;
					cout<<endl;
				}
			}
		}
};
int main(){
	ShortestPath a;
	ShortestPath b;
	ShortestPath c;
	cout<<"1 : DIJKSTRA | 2 : BELLMAN-FORD | 3 : FLOYD-WARSHALL "<<endl;
	int k;
	cout<<"LUA CHON: ";
	cin>>k;
	if(k==1){
		freopen("input.txt", "r", stdin);
		a.Create();
		a.Dijkstra();
		a.Output();
	}
	else if(k==2){
		freopen("bellman.txt", "r", stdin);
		b.Create();
		b.Bellmanford();
		b.Output();
	}
	else{
		cout<<"KHONG CO THUAT TOAN NAO DUOC THUC HIEN";
	}
	return 0;
}
