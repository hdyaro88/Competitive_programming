#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};
string path = "DULR";
int n , m;
void bfs(queue<pair<int , int>> &q ,  vector<vector<char>> &mat , vector<vector<char>> &vis) {
		if(q.empty()) {
			return;
		}
		
		pair<int , int> pr = q.front();
		q.pop();
		int rw = pr.first , col = pr.second;
		
		if(mat[rw][col] == 'B') {
			return;
		}
		
		for(int i = 0 ; i < 4 ; i++) {
			int x = rw + dx[i];
			int y = col + dy[i];
			char ch = path[i];
			if(x >= 0 && x < n && y >= 0 && y < m) {
				if(vis[x][y] != '*' || mat[x][y] == '#') continue;
				q.push({x , y});
				vis[x][y] = ch;
			}
		}
		
		bfs(q , mat , vis);
		
}


int main() {
	cin >> n >> m;
	vector<vector<char>> vis(n , vector<char> (m , 0));
	vector<vector<char>> mat(n , vector<char> (m , 0));
	pair<int , int> st , ed;
	for(int i = 0; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			cin >> mat[i][j];
			if(mat[i][j] == 'A') {
				st.first = i;
				st.second = j;
			}
			else if(mat[i][j] == 'B') {
				ed.first = i;
				ed.second = j;
			}
			vis[i][j] = '*';
		}
	}
	
	
	queue<pair<int , int>> q;
	q.push(st);
	bfs(q ,mat , vis);
	
	unordered_map<char , char> mp;
	mp['L'] = 'R';
	mp['R'] = 'L';
	mp['U'] = 'D';
	mp['D'] = 'U';
	
	if(vis[ed.first][ed.second] == '*') {
		cout << "NO" << endl;
	}
	else {
		
		int i = ed.first , j = ed.second;
		string step;
		while(i != st.first || j != st.second) {
			step.push_back(vis[i][j]);
			if(vis[i][j] == 'L') j++;
			else if(vis[i][j] == 'R') j--;
			else if(vis[i][j] == 'U') i++;
			else i--;
		}
		reverse(step.begin() , step.end());
		cout << "YES" << endl;
		cout << step.size() << endl;
		cout << step << endl;
	} 
}
