#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 2505;
 
int score[MAX] , safe[MAX];
int scr , n , m;
 
int dfs(int node , vector<vector<pair<int , int>>> &edges , vector<int> &vis , int cyc , int lscore) {
	
	if(vis[node] == 1) {
		if(score[node] < lscore)
		cyc = 1;
	}
	
	if((node == 1 && vis[node]) || (node == n && cyc)) {
		return -1;
	}
	
	score[node] = max(score[node] , lscore);
	
	vis[node]++;
	
	for(auto pr : edges[node]) {
		int next = pr.second;
		int wt = pr.first;
		if((safe[next] && score[next] >= lscore + wt) ||  vis[next] == 2) continue;
		if(dfs(next , edges , vis , cyc , lscore + wt) == -1) {
			return -1;
		}
	}
	vis[node]--;
	
	safe[node] = 1;
	
	return 0;
	
}
 
 
int getPath(int node , vector<vector<pair<int , int>>> &edges , vector<int> &vis ,  vector<int> &dp , int lscore) {
	
	if(dp[node] != LLONG_MIN) {
		return dp[node];
	}
	
	if(node == n) {
		return 0;
	}
	
	int mx = LLONG_MIN;
	
	vis[node] = 1;
	
	for(auto pr : edges[node]) {
		int next = pr.second;
		int wt = pr.first;
		if(vis[next] && dp[next] == LLONG_MIN) continue;
		if(getPath(next , edges , vis , dp , lscore + wt) == LLONG_MIN) continue;
		mx = max(mx , wt + getPath(next , edges , vis , dp , lscore + wt));
	}
	
	
	return (dp[node] = mx);
 
}
 
 
 
signed main() {
	
	cin >> n >> m;
	vector<vector<pair<int , int>>> edges(n + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		edges[u].push_back({w , v});
	}	
	
//	if(n == 6 && m == 8) {
//		cout << 3 << endl;
//		exit(0);
//	}
	
	vector<int> vis(n + 1 , 0);
	int lscore = 0;
	if(dfs(1 , edges , vis , 0 , lscore) == -1) {
		cout << -1 << endl;
		exit(0);
	}
	
	vector<int> dp(n + 1 , LLONG_MIN);
	lscore = 0;
	vis.assign(n + 1 , 0);
	
	getPath(1 , edges , vis , dp , lscore);
	
	cout << dp[1] << endl;
	
}
 
