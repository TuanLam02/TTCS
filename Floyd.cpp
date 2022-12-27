#include<iostream>
#include<fstream>
#define maxn 100
using namespace std;
int matrix[maxn][maxn];
int num_vertex;
int num_distance;
int w[maxn][maxn],trace[maxn][maxn];
int check[maxn];
void Create(){
	freopen("floyd.txt","r",stdin);
	cin>>num_vertex;
	cin>>num_distance;
	for(int i=1;i<=num_vertex;i++){
		for(int j=1;j<=num_vertex;j++){
			if(i==j){
				matrix[i][j]=0;
			}else{
				matrix[i][j]=INT_MAX;
			}
		}
	}
	for(int i=1;i<=num_distance;i++){
		int u,v;
		cin>>u;
		cin>>v;
		cin>>matrix[u][v];
	}	
}
void Floyd(){
	int k=1,i=1,j=1;
	w[i][j]=0;
	for(k=1;k<=num_vertex;k++){
		for( i=1;i<=num_vertex;i++){
			for(j=1;j<=num_vertex;j++){
				trace[i][j]=i;
				if(i!=k && j!=k && matrix[i][j]>matrix[i][k]+matrix[k][j] && matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX){
					matrix[i][j]=matrix[i][k]+matrix[k][j];
					trace[i][j]=k;
				}

			}
		}	
	}
}
void Output(){
	for(int i=1;i<=num_vertex;i++){
		for(int j=1;j<=num_vertex;j++){
			if(matrix[i][j]!=INT_MAX && i!=j){
				cout<<"KHOANG CACH GIUA: "<<i<<" VA "<<j<<" LA: "<<matrix[i][j]<<endl;
			}
		}	
	}
}
int main(){
	freopen("floyd.txt","r",stdin);
	Create();
	Floyd();
	Output();
}

