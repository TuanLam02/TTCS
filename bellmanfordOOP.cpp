#include<iostream>
#include<fstream>
#define maxn 100
using namespace std;
class Bellman{
	private:
		int matrix[maxn][maxn];
		int num_vertex;
		int num_distance;
		int start;
		int w[maxn];
		int trace[maxn];
		int check[maxn];
	public:
		void Create(){
			cin>>num_vertex>>num_distance;
			cin>>start;
			for(int i=1;i<=num_vertex;i++){
				for(int j=1;j<=num_vertex;j++){
					matrix[i][j]=INT_MAX;
				}
			}
			for(int i=1;i<=num_distance;i++){
				int u,v;
				cin>>u>>v;
				cin>>matrix[u][v];
			}
		}
		void Bellmanford(){
			for(int i=1;i<=num_vertex;i++){
				check[i]=true;
				w[i]=INT_MAX;
			}
			
			int r=start,index;
			w[r]=0;
			for(int i=1;i<=num_vertex;i++){
				index=INT_MAX;
				if(r!=i){
					for(int j=1;j<=num_vertex;j++){
						if(check[j]==true && index>w[j]){
							index=w[j];
							r=j;
						}
					}
					check[i]=false;
					check[r]=false;
					for(int j=1;j<=num_vertex;j++){
						if(matrix[r][j]!=INT_MAX && w[j]>w[r]+matrix[r][j]){
							w[j]=w[r]+matrix[r][j];
							trace[j]=r;
						}
					}
				}
			}
		}
		void Output(){
			for(int i=1;i<=num_vertex;i++){
				if(start==i || w[i]==INT_MAX){
					cout<<"KHONG CO DUONG DI DEN "<<i<<endl;
				}else{
					cout<<"TRONG SO DI DEN "<<i<<" LA: "<<w[i]<<endl;
					cout<<"DUONG DI DEN "<<i<<" LA: "<<endl;
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
	freopen("bellman.txt","r",stdin);
	freopen("bellman1.txt","w",stdout);
	Bellman a;
	a.Create();
	a.Bellmanford();
	a.Output();
	return 0;
}
