#include<bits/stdc++.h>
using namespace std;
int parent[100000 + 7];

int dfs(int node , vector<vector<int>> &edges , vector<int> &vis , int cnt , vector<int> &team) {	
	team[node] = (cnt % 2 ? 2 : 1);
	vis[node] = 1;	
	int ans = 1;	
	for(auto next : edges[node]) {
		if(team[node] == team[next]) return 0;
		if(vis[next]) continue;
		ans = dfs(next , edges , vis , cnt + 1 , team);
		if(!ans) return ans;
	}
	return ans;
}

int find(int x) {
	if(parent[x] == x) return x;
	return (parent[x] = find(parent[x]));
}



int main() {
	int n , m;
	cin >> n >> m;
	iota(parent , parent + n + 1 , 0);
	
	vector<vector<int>> edges(n + 1);
	for(int i = 0 ; i < m ; i++) {
		int x , y; cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	vector<int> vis(n + 1 , 0);
	vector<int> team(n + 1 , 0);
	for(int i = 1 ; i <= n ; i++) {
		if(!vis[i]) {
			if(!dfs(i , edges , vis , 0 , team)) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++) {
		cout << team[i] << " ";
	}
	cout << endl;
}
