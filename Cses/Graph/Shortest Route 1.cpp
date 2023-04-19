#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
	int n , m;
	cin >> n >> m;
	vector<vector<pair<int , int>>> edges(n + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int x , y , z;
		cin >> x >> y >> z;
		edges[x].push_back({y , z});
//		edges[y].push_back({x , z});
	}
	
	vector<int> dist(n + 1 , LLONG_MAX);
	vector<int> vis(n + 1 , 0);
	dist[1] = 0;
	
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	pq.push({0 , 1});
	while(!pq.empty()) {
		
		pair<int , int> prr = pq.top();
		int node = prr.second;
		pq.pop();
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto pr : edges[node]) {
			int next = pr.first;
			int wt = pr.second;
			if(vis[next]) continue;
			dist[next] = min(dist[next] ,  dist[node] + wt);
			pq.push({dist[next] , next});
		}
	}
	
	for(int i = 1 ; i <= n ; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
}
