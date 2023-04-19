#include<bits/stdc++.h>
using namespace std;


int dfs(int node , vector<vector<int>> &edges , vector<int> &vis , vector<int> &path , int cnt) {
	
	if(vis[node]) {
		if(cnt - vis[node] >= 2) {
			path.push_back(node);
			return 1;
		}
		return 0;
	}
	
	path.push_back(node);
	
	
	vis[node] = cnt;
	
	for(auto next : edges[node]) {
		if(vis[next] == -1) continue;
		if(dfs(next , edges , vis , path , cnt + 1)) {
			return 1;
		}
	}
	
	path.pop_back();
	
	vis[node] = -1;
	
	return 0;
}

int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>> edges(n + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int x , y;
		cin >> x >> y;
		edges[x].push_back(y);
	}
	
	vector<int> vis(n + 1 , 0);
	
	int flg = 0;
	vector<int> path;
	
	for(int i = 1 ; i <= n ; i++) {
		if(vis[i] != -1) {
			if(dfs(i , edges , vis , path , 0)) {
				flg = 1;
				break;
			}
		}
	}
	
	if(flg) {
		vector<int> res;
		for(int i = 0 ; i < path.size() ; i++) {
			if(res.empty() && path[i] == path.back()) {
				res.push_back(path[i]);
			}
			else if(res.size() > 0) {
				res.push_back(path[i]);
			}
		}
		cout << res.size() << endl;
		for(auto el : res) {
			cout << el << " ";
		}
		cout << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}
}
