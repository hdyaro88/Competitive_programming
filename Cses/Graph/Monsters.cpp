#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1 , -1, 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};
string path = "DULR";
void bfs(queue<pair<pair<int , int> , int>> &q , vector<vector<int>> &min_mon , vector<vector<char>> &mat , vector<vector<int>> &vis) {
	if(q.empty()) return;
	pair<pair<int , int> , int> pr = q.front();
	q.pop();
	int rw = (pr.first).first , col = (pr.first).second , cnt = pr.second;
	int n = min_mon.size() , m = min_mon[rw].size();
	
	
	min_mon[rw][col] = min(min_mon[rw][col] , cnt);
	
	vis[rw][col] = 1;
	
	for(int i = 0 ; i < 4 ; i++) {
		int x = rw + dx[i];
		int y = col + dy[i];
		
		if(x >= 0 && x < n && y >= 0 && y < m) {
			if(mat[x][y] == 'M') continue;
			else if(vis[x][y]) {
				if(mat[x][y] == '.' && mat[rw][col] == '.') continue;
				if(mat[x][y] == 'M') continue; 
			}
			else if(mat[x][y] != '.') continue;
			q.push({{x , y} , cnt + 1});
			vis[x][y] = 1;
		}
	}
	bfs(q , min_mon , mat , vis);
}

int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<char>> mat(n , vector<char>(m));
	vector<vector<int>> min_mon(n , vector<int>(m , INT_MAX));
	
	int x , y , a = -1 , b = -1;
	
	for(int i = 0 ; i < n ;i++) {
		for(int j = 0 ; j < m ; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == 'M') {
				min_mon[i][j] = 0;
			}
			if(mat[i][j] == 'A') {
				x = i;
				y = j;
			}
		}
	}
	
	vector<vector<int>> vis(n , vector<int>(m , 0));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(mat[i][j] == 'M' && !vis[x][y]) {
				queue<pair<pair<int , int> , int>> q;
				q.push({{i , j} , 0});
				bfs(q , min_mon , mat , vis);
			}
		}
	}
	
	
//	for(int i = 0 ; i < n ; i++) {
//		for(int j = 0 ; j < m ; j++) {
//			cout << min_mon[i][j] << " " ;
//		}
//		cout << endl;
//	}
	

	queue<pair<pair<int , int> , int>> q;
	q.push({{x , y} , 0});
	vector<vector<int>> vis1(n , vector<int>(m , 0));
	vector<vector<char>> parent(n , vector<char> (m));
	while(!q.empty()) {
		pair<pair<int , int> , int> pr = q.front();
		q.pop();
		int rw = (pr.first).first , col = (pr.first).second , cnt = pr.second;
		vis1[rw][col] = 1;
		
		if(rw == n - 1 || rw == 0 || col == m - 1 || col == 0) {
			if(min_mon[rw][col] > cnt) {
				a = rw , b = col;
				cout << "YES" << endl;
				break;
			}
		}
		
		
		for(int i = 0 ; i < 4 ; i++) {
		int x = rw + dx[i];
		int y = col + dy[i];
		char ch = path[i];
		
		if(x >= 0 && x < n && y >= 0 && y < m) {
			if(vis1[x][y] || mat[x][y] != '.') continue;
			if(min_mon[x][y] <= cnt + 1) continue;
			q.push({{x , y} , cnt + 1});
			parent[x][y] = ch;
			vis1[x][y] = 1;
		}
	}
	}
	
	if(a == -1 && b == -1) {
		cout << "NO" << endl;
		return 0;
	}
	int i = a , j = b;
	string ans;
	while(i != x || j != y) {
		ans.push_back(parent[i][j]);
		if(parent[i][j] == 'D') i--;
		else if(parent[i][j] == 'U') i++;
		else if(parent[i][j] == 'L') j++;
		else j--;
	}
	reverse(ans.begin() , ans.end());
	cout << ans.size() << endl;
	cout << ans << endl;
}
