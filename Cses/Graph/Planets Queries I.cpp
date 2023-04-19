#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAX = 30;
int n , m;
int dp[MAXN][MAX];


void pre() {
	
	for(int i = 1 ; i < MAX ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			dp[j][i] = dp[dp[j][i - 1]][i - 1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> edges(n + 1);
	for(int i = 0 ; i < m ; i++) {
		int x; cin >> x;
		edges[i + 1].push_back(x);
	}
	
	queue<int> q;
	
	vector<int> dist(n + 1 , INT_MAX);
	
	dist[1] = 0;
	q.push(1);
	
	while(!q.empty()) {
		
		int node = q.front();
		q.pop();
		
		if(vis[node]) continue;
		
		vis[node] = 1;
		
		for(auto next : edges[node])  {
			dist[next] = min(dist[next] , dist[node] + 1);
			q.push(next);
		}
	}
	
	while(m--) {
		int x , b; cin >> x >> b;
	
		for(int i = 0 ; i < MAX ; i++) {
			
		}
		
		cout << x << endl;
	}
}
