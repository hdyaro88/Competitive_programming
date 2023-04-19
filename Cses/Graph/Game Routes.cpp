#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int n , m;
const int mod = 1e9 + 7;

int dfs(int node , vector<vector<int>> &edges) {
	
	if(dp[node] != -1) {
		return dp[node];
	}
	
	if(node == n) {
		return 1;
	}
	
	int ans = 0;
	
	for(auto next : edges[node]) {
		(ans += dfs(next , edges)) % mod;
		ans %= mod;
	}
	
	return (dp[node] = ans);
}

int main() {

	cin >> n >> m;
	dp.resize(n + 1 , -1);
	
	vector<vector<int>> edges(n + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int x , y;
		cin >> x >> y;
		edges[x].push_back(y);
	}
	
	
	cout << dfs(1 , edges) << endl;
}
