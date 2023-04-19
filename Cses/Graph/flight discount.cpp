#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
	int n , m;
	cin >> n >> m;
	vector<tuple<int , int , int>> edg;
	vector<vector<pair<int , int>>> edges(n + 1);
	vector<vector<pair<int , int>>> redges(n + 1);
	
	vector<int> f_dist(n + 1 , LLONG_MAX) , b_dist(n + 1 , LLONG_MAX);
	
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	
	for(int i = 0 ; i < m ; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		edg.push_back(make_tuple(u , v , w));
		edges[u].push_back({w , v});
		redges[v].push_back({w , u});
	}
	
	vector<int> vis(n + 1 , 0);
	
	pq.push({0 , 1});
	
	f_dist[1] = b_dist[n] = 0;
	
	while(!pq.empty()) {
		int node = (pq.top()).second;
		
		pq.pop();
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto pr : edges[node]) {
			int next = pr.second;
			int wt = pr.first;
			if(vis[next]) continue;
		
			f_dist[next] = min(f_dist[next] , f_dist[node] + wt);
			pq.push({f_dist[next] , next});
		}
	}
	vis.assign(n + 1 , 0);
	
	pq.push({0 , n});
	
	while(!pq.empty()) {
		int node = (pq.top()).second;
		int wt = (pq.top()).first;
		pq.pop();
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto pr : redges[node]) {
			int next = pr.second;
			int wt = pr.first;
			if(vis[next]) continue;
			
			b_dist[next] = min(b_dist[next] , b_dist[node] + wt);
			pq.push({b_dist[next] , next});
		}
	}

	
	int ans = LLONG_MAX;
	
	for(auto edge : edg) {
		int u , v , w;
		tie(u , v , w) = edge;
		if(f_dist[u] != LLONG_MAX && b_dist[v] != LLONG_MAX) {
//		cout << u << " " << v << " " << f_dist[u] << " " << b_dist[v] << endl;
		ans = min(ans , f_dist[u] + b_dist[v] + (w / 2));
		}
	}
	
	cout << ans << endl;
	
}
