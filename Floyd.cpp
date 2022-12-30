#include <fstream>
#include <iostream>
#define maxn 100
using namespace std;
int matrix[maxn][maxn];
int num_vertex;
int num_distance;
int w[maxn][maxn], trace[maxn][maxn];
int check[maxn];
void Create() {
    freopen("floyd.txt", "r", stdin);
    cin >> num_vertex;
    cin >> num_distance;
    for (int i = 1; i <= num_vertex; i++) {
        for (int j = 1; j <= num_vertex; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 1; i <= num_distance; i++) {
        int u, v;
        cin >> u;
        cin >> v;
        cin >> matrix[u][v];
    }

}
void Floyd() {
	for (int i = 1; i <= num_vertex; i++) {
        for (int j = 1; j <= num_vertex; j++) {
            if (matrix[i][j] != INT_MAX)
            	trace[i][j] = j;
        }
    }
    int k = 1, i = 1, j = 1;
    for (k = 1; k <= num_vertex; k++) {
        for (i = 1; i <= num_vertex; i++) {
            for (j = 1; j <= num_vertex; j++) {
                if (i != k && j != k && matrix[i][j] > matrix[i][k] + matrix[k][j] && matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }

}
void Output() {
    for (int i = 1; i <= num_vertex; i++) {
        for (int j = 1; j <= num_vertex; j++) {
            if (matrix[i][j] != INT_MAX && i != j) {
                cout << "KHOANG CACH GIUA: " << i << " VA " << j << " LA: " << matrix[i][j];
                cout << " - DUONG DI: " << i << " -> ";
                int k = trace[i][j];
                while (k != j) {
                    cout << k << " -> ";
                    k = trace[k][j];
                }
                cout << j << endl;
            }
        }
    }
}
void printMatrix(int matrix[][maxn], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    freopen("floyd.txt", "r", stdin);
    Create();
    Floyd();
    Output();
}
