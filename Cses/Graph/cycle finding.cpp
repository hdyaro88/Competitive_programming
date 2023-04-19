#include<bits/stdc++.h>
#define int long long
using namespace std;

long long const inf = 1e10;

 
signed main() {
	int n , m; 
	cin >> n >> m;
	
	vector<tuple<int , int , int>> edges;
	vector<int> path;
	
	for(int i = 0 ; i < m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		if(u == v && w < 0) {
			path = {u , v};
		}
		edges.push_back(make_tuple(u , v , w));
	}
	
	
	if(!path.empty()) {
		cout << "YES" << endl;
		for(auto el : path) {
			cout << el << " ";
		}
		cout << endl;
		exit(0);
	}
	
	int u , v , w;
	
	vector<int> dist(n + 1 , inf);
	vector<int> pred(n + 1 , -1);
	
	dist[1] = 0;
	int neg_cycle_start = -1;
	for(int i = 0 ; i < n  ; i++) {
		for(auto edge : edges) {
			tie(u , v , w) = edge;
			if(dist[v] > dist[u] + w) {
				dist[v] = min(dist[v] , dist[u] + w);
				pred[v] = u;
			}
		}
	}
	
	for(auto edge : edges) {
			tie(u , v , w) = edge;
			if(dist[v] > dist[u] + w) {
				neg_cycle_start = v;
				break;
			}
		}
	
	vector<int> vis(n + 1 , 0);
	
//	for(int i = 1 ; i <= n ; i++) {
	vector<int> tmp;
	int i = neg_cycle_start;
//		unordered_map<int , int> mp;
//		if(pred[i] != -1) {
			tmp.push_back(i);
			int next = pred[i];
			while(next != i) {
//				if(mp[next]) break;
//				mp[next] = 1;
				if(pred[next] == -1) break;
				tmp.push_back(next);
				next = pred[next];
			}
//			if(next == i) {
				tmp.push_back(next);
				copy(tmp.rbegin() , tmp.rend() , back_inserter(path));
//				break;
//			}
//			mp.clear();
//		}
//	}
	
	
	if(path.empty()) {
		cout << "NO" << endl;
		exit(0);
	}
	
	cout << "YES" << endl;
	
	for(auto el : path) {
		cout << el << " ";
	}
	cout << endl;
	
}
