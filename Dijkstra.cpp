#include <iostream>
#include <fstream>
#define maxn 1000
#define maxf 1000
using namespace std;
int a[maxn][maxn],n,m,s,e;
int f[maxn],vet[maxn],checkdinh[maxn];
void docfile(){
	fstream inp("input.txt");
	inp>>n>>m;
	inp>>s>>e;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			a[i][j] = -1;
		}
	}
	for(int i=1; i<=m; i++){
		int u,v;
		inp>>u>>v;
		inp>>a[u][v];
		a[u][v] = a[v][u];
	}
	inp.close();
}
void dijkstra(){
	for(int i = 1; i < n; i++){
		f[i]=maxf;
		checkdinh[i]=true;
	}
	f[s]=0;
	int v=s, fmin;
	while(v!=e){// dinh dau khac dinh cuoi
		fmin=maxf;
		for(int i = 1; i <= n; i++){
			if(checkdinh[i] && fmin>f[i]){
				fmin=f[i];
				v=i;
			}
		}
		if(fmin==maxf) break;
		checkdinh[v]=false;
		for(int i = 1; i<=n;i++){
			if(a[v][i]>0 && f[i]>f[v]+a[v][i]){
				f[i]=f[v]+a[v][i];
				vet[i]=v;
			}
		}
	}
}
void ketqua(){
	cout<<f[e];
}
main(){
	docfile();
	dijkstra();
	ketqua();
}
