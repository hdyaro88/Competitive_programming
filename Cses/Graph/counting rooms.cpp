#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0  , 1 , -1};

void bfs(int rw , int col , vector<vector<int>> &mat , vector<vector<int>> &vis) {
	int n = mat.size() , m = mat[rw].size();
	vis[rw][col] = 1;
	
	for(int i = 0 ; i < 4 ; i++) {
		int x = rw + dx[i];
		int y = col + dy[i];
		if(x >= 0 && x < n && y >= 0 && y < m) {
			if(vis[x][y] || !mat[x][y]) continue;
			bfs(x , y , mat , vis);
		}
	}
}

int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> vis(n , vector<int> (m , 0));
	vector<vector<int>> mat(n , vector<int>(m , 0));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0; j < m ; j++) {
			char x; cin >> x;
			if(x == '#') mat[i][j] = 0;
			else mat[i][j] = 1;
		}
	}
	int ans = 0;
	
	for(int i = 0 ; i < n  ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(!vis[i][j] && mat[i][j]) {
				bfs(i , j , mat , vis);
				ans++;
			}
		}
	}
	
	cout << ans << endl;
	
	
}
