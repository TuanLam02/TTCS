#include <fstream>
#include <iostream>
#define maxn 100
using namespace std;
class ShortestPath{
	private:
		int matrix[maxn][maxn];
		int number_vertex;
		int number_distance;
		int start;
		int weight[maxn],trace[maxn],check[maxn];
	public:
		void Create(){
			cin>>this->number_vertex;
			cin>>this->number_distance;
			cin>>this->start;
			for(int i=1;i<=this->number_vertex;i++){
				for(int j=1;j<=this->number_vertex;j++){
					this->matrix[i][j]=INT_MAX;
				}
			}
			for(int i=1;i<=this->number_distance;i++){
				int u,v;
				cin>>u>>v;
				cin>>this->matrix[u][v];
				this->matrix[v][u]=this->matrix[u][v];
			}
		}
		void Dijkstra(){
			for(int i=1;i<=this->number_vertex;i++){
				check[i]=true;
				weight[i]=INT_MAX;
			}
			trace[maxn]=this->start;
			int point=this->start,fmin;
			weight[point]=0;
			int k=0;
			while(k<=this->number_vertex){
				if(point!=k){
					fmin=INT_MAX;
					for(int j=1;j<=this->number_vertex;j++){
						if( this->check[j]==true && fmin>weight[j] ){
							fmin=weight[j];
							point=j;
						}
					}
					check[k]=false;
					check[point]=false;
					for(int j=1;j<=this->number_vertex;j++){
						if(this->matrix[point][j]!=INT_MAX&&weight[j]>this->weight[point]+matrix[point][j]){
							weight[j]=weight[point]+matrix[point][j];
							trace[j]=point;
						}
					}
				}
				k++;
			}
		}
		void Output(){
			for(int i=1;i<=this->number_vertex;i++){
				if(start==i){
					cout<<"KHONG CO DUONG DI DEN: "<<i;
					cout<<endl;
					cout<<endl;
				}
				else{
					cout<<"TRONG SO DUONG DI DEN "<<i<<" LA: "<<weight[i]<<endl;
					cout<<"DUONG DI DEN "<<i<<" LA: ";
					int path[maxn],d=0;
					int k=i;
					d++;
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
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	a.Create();
	a.Dijkstra();
	a.Output();
	return 0;
}
