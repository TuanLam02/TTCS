#include<iostream>
#include<fstream>
#define maxn 100
#define maxf 10000000
using namespace std;
int a[maxn][maxn],n,m,s,e;
int f[maxn],vet[maxn],check[maxn];
void docfile(){
	fstream inp("input.txt");
	inp>>n>>m;
	inp>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=maxf;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;
		inp>>u>>v;
		inp>>a[u][v];
		a[v][u]=a[u][v];
	}
	inp.close();
}
void dijkstra(){
	for(int i=1;i<=n;i++){
		check[i]=true;
		f[i]=maxf;
	}
	vet[maxn]=s;
	int v=s, minf;
	f[v]=0;
	int k=0;
	while(k<=n){
		if(v!=k){
			minf=maxf;
			for(int j=1;j<=n;j++){
				if(check[j]==true&&minf>f[j]){
					minf=f[j];
					v=j;
				}
			}
			check[k]=false;
			check[v]=false;
			for(int j=1;j<=n;j++){
				if(a[v][j]!=maxf&&f[j]>f[v]+a[v][j]){
					f[j]=f[v]+a[v][j];
					vet[j]=v;
				}
			}
		}
		k++;
		
	}
}
void output(){
	
	for(int i=1;i<=n;i++){
		if(s==i){
			cout<<"Khong co duong di den: "<<i<<endl;
			cout<<endl;
		} 
		else{
			cout<<"Trong so di den "<<i<<" la: "<<f[i]<<endl;
			cout<<"Duong di la: ";
			int duong[maxn], d=0;
			d++;
			int k=i;
			duong[d]=k;
			while(vet[k]!=0){
				k=vet[k];
				d++;
				duong[d]=k;
			}
			for(int j=d;j>0;j--){
			cout<<duong[j]<<" ";
			}
			cout<<endl;
			cout<<endl;
		}
		
	}	
}
int main(){
	docfile();
	dijkstra();
	output();
}
