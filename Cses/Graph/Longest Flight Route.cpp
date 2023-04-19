#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dp;
int n;

int dfs(int node , vector<vector<int>> &edges) {
	
	if(dp[node] != -1) {
		return dp[node];
	}
	
	if(node == n) return 1;
	
	int ans = -1;
	
	for(auto next : edges[node]) {
		int res = dfs(next , edges);
		if(res != -1)
		ans = max(ans , res + 1);
	}
	
	return (dp[node] = ans);
}

void dfs2(int node , vector<vector<int>> &edges , vector<int> &path , int cnt) {
	
	if(node == n) {
		return;
	}
	
	for(auto next : edges[node]) {
		if(dp[next] == dp[1] - cnt) {
			path.push_back(next);
			dfs2(next , edges , path , cnt + 1);
			break;
		}
	}
	
}

signed main() {
	int m;
	cin >> n >> m;
	dp.resize(n + 1 , -1);
	dp[n] = 0;
	vector<vector<int>> edges(n + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int u ,  v;
		cin >> u >> v;
		edges[u].push_back(v);
	}
	
	queue<int> q;
	vector<int> vis(n + 1 , 0);
	q.push(1);
	
	while(!q.empty()) {
		int node = q.front(); q.pop();
		if(vis[node]) continue;
				
		vis[node] = 1;
		
		for(auto next : edges[node]) {
			if(vis[next]) continue;
			q.push(next);
		}
	}
	
	if(!vis[n]) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	
	
	vector<int> path = {1};
	
	dfs(1 , edges);
	
	if(dp[1] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	dfs2(1 , edges , path , 1);
	
	cout << path.size() << endl;
	for(auto el : path) {
		cout << el << " ";
	}
	cout << endl;
}
