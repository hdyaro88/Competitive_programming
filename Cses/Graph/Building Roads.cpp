#include<bits/stdc++.h>
using namespace std;
//#define MAX 100000 + 7
//int parent[MAX];
//
//
//int union_find(int u , int v) {
//	int u = find_parent(u);
//	int v = find_parent(v);
//	if(v == u) return 0;
//	parent[u] = v;
//	return 1;
//}

void dfs(int node , vector<vector<int>> &edges , vector<int> &vis) {
	vis[node] = 1;
	for(auto next : edges[node]) {
		if(vis[next]) continue;
		dfs(next , edges , vis);
	}
}

int main() {
	int v , e; cin >> v >> e;
	vector<vector<int>> edges(v + 1);
//	iota(par, par + v , 0);
	
	for(int i = 0 ; i < e ; i++) {
		int x , y; cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int node = -1;
	vector<pair<int , int>> ans;
	vector<int> vis(v + 1 , 0);
	
	for(int i = 1 ; i <= v ; i++) {
		if(!vis[i]) {
			dfs(i , edges , vis);
			if(node != -1) {
				ans.push_back({i , node});
			}
			else node = i;
		}
		
	}
	
	cout << ans.size() << endl;
	for(auto pr : ans) {
		cout << pr.first << " " << pr.second << endl;
	}
}
