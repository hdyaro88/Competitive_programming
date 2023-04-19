#include<bits/stdc++.h>
using namespace std;
 
int dfs(int node , vector<vector<int>> &edges , vector<int> &vis , int cnt , vector<int> path , vector<int> &ans) {
	
	path.push_back(node);
	
	if(vis[node]) {
		if(cnt - vis[node] >= 3) {
			for(auto el : path) {
				if(el == node || ans.size() > 0) ans.push_back(el);
			}
		}
		return 0;
	}
	
	vis[node] = cnt;
	
	for(auto next : edges[node]) {
//		if(vis[next]) continue;
//		path.push_back(next);
		dfs(next , edges , vis , cnt + 1  , path , ans);
//		path.pop_back();
		if(ans.size() > 0) {
			return 0;
		}
	}
	path.pop_back();
	return 1;
}
 
 
 
int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> edges(n + 1);
	for(int i = 0 ; i < m ; i++) {
		int x , y; cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	vector<int> path , ans;
	vector<int> vis(n + 1 , 0);
	int flg = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(!vis[i]) {
			if(!dfs(i , edges , vis , 1 , path , ans)) {
				flg = 1;
				break;
			}
		}
	}
	if(!flg) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(auto el : ans) {
		cout << el << " ";
	}
	cout << endl;
}

