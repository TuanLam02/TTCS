#include <fstream>
#include <iostream>
#define maxn 100
using namespace std;
int matrix[maxn][maxn];
int number_vertex;
int number_distance;
int start;
int f[maxn];
int trace[maxn];
int check[maxn];
void Input(){
	cin>>number_vertex>>number_distance;
	cin>>start;
	for(int i=1;i<=number_vertex;i++){
		for(int j=1;j<=number_vertex;j++){
			matrix[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=number_distance;i++){
		int u,v;
		cin>>u>>v;
		cin>>matrix[u][v];
		matrix[v][u]=matrix[u][v];
	}
}
void Dijkstra(){
	for(int i=1;i<=number_vertex;i++){
		check[i]=true;
		f[i]=INT_MAX;
	}
	trace[maxn]=start;
	int point=start;
	int min;
	f[point]=0;
	int k=0;
	while(k<=number_vertex){
		if(point!=k){
			min=INT_MAX;
			for(int j=1;j<=number_vertex;j++){
				if(check[j]==true&&min>f[j]){
					min=f[j];
					point=j;
				}
			}
			check[k]=false;
			check[point]=false;
			for(int j=1;j<=number_vertex;j++){
				if( matrix[point][j]!=INT_MAX && f[j]>f[point]+matrix[point][j]){
					f[j]=f[point]+matrix[point][j];
					trace[j]=point;
				}
			}
		}
		k++;
		
	}
}
void Output(){
	for(int i=1;i<=number_vertex;i++){
		if(start==i){
			cout<<"KHONG CO DUONG DI DEN "<<i;
			cout<<endl;
			cout<<endl;
		}
		else{
			cout<<"TRONG SO DUONG DI DEN "<<i<<" LA: "<<f[i]<<endl;
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
int main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	Input();
	Dijkstra();
	Output();
}
