#include<bits/stdc++.h>
using namespace std;

int n , m;
const int mod = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> m;

	vector<vector<pair<long long, int>>> edges(n + 1);
	
	priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long , int>>> pq;
	vector<int> mn_paths(n + 1 , 0);
	
	
	for(int i = 0 ; i < m ; i++) {
		int x , y , z;
		cin >> x >> y >> z;
		edges[x].push_back({z , y});
	}
	
	
	vector<int> vis(n + 1 , 0);
	vector<long long> dist(n + 1 , LLONG_MAX);
	
	dist[1] = 0;
	
	
	pq.push({0 , 1});
	
	while(!pq.empty()) {
		pair<int , int> pr = pq.top();
		pq.pop();
		
		int node = pr.second;
		
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto pr : edges[node]) {
			int next = pr.second;
			long long wt = pr.first;
			if(dist[next] > dist[node] + wt) {
				dist[next] = dist[node] + wt;
			}
			pq.push({dist[next] , next});
		}
	}
	
	vector<long long> t_dist(n + 1 , LLONG_MAX);
	vector<int> mn(n + 1 , INT_MAX) , mx(n + 1 , INT_MIN);
	
	mn[1] = mx[1] = 0;
	
//	prioriryt_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
	vis.assign(n + 1 , 0);
	
	pq.push({0 , 1});
	t_dist[1] = 0;
	mn_paths[1] = 1;
	while(!pq.empty()) {
		auto pr = pq.top();
		pq.pop();
		
		int node = pr.second;
		
		
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto pr : edges[node]) {
			int next = pr.second;
			int wt = pr.first;
			
			if(t_dist[node] + wt == dist[next]) {
				mn[next] = min(mn[next] , mn[node] + 1);
				mx[next] = max(mx[next] , mx[node] + 1);
				(mn_paths[next] += mn_paths[node]) % mod;
				mn_paths[next] %= mod;
			}
			
			if(t_dist[next] > t_dist[node] + wt) {
				t_dist[next] = t_dist[node] + wt;
			}
			
			pq.push({t_dist[next] , next});
		}
	}
	
	cout << dist[n] << " " << mn_paths[n] << " " << mn[n] << " " << mx[n] << endl;
}
