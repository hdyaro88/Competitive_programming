#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
	int n , m , k;
	cin >> n >> m >> k;
	priority_queue<int> dist[n + 1];
//	vector<int> dist(n + 1 , LLONG_MAX);
	vector<vector<pair<int , int>>> edges(m + 1);
	
	for(int i = 0 ; i < m ; i++) {
		int u , v , w; cin >> u >> v >> w;
		edges[u].push_back({w , v});
//		edges[v].push_back({w , u});
	}
	
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	
	pq.push({0 , 1});
//	dist[1] = 0;
	
	while(!pq.empty()) {
		auto pr = pq.top();
		pq.pop();
		int wts = pr.first;
		int node = pr.second;
		
		if(!dist[node].empty() && wts > dist[node].top()) continue;
 
		
		for(auto pr1 : edges[node]) {
			int wt = pr1.first;
			int next = pr1.second;
			int tmp = wts + wt;
//			if(!dist[next].empty() && tmp > dist[next].top()) {
//				continue;
//			}
			if(dist[next].empty()) {
				dist[next].push(tmp);
				pq.push({tmp , next});
			}
			else if(dist[next].size() < k) {
				dist[next].push(tmp);
				pq.push({tmp , next});
			}
			else if(tmp < dist[next].top()) {
				dist[next].pop();
				dist[next].push(tmp);
				pq.push({tmp , next});
			}
		}
	}
	
	int ans[k];
	int i = k;
	while(!dist[n].empty()) {
		ans[--i] = dist[n].top();
		dist[n].pop();
	}
	
	for(int i = 0 ; i < k ; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
}
