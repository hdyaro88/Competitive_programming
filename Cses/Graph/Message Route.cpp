#include<bits/stdc++.h>
using namespace std;

int main() {
	int v , e;
	cin >> v >> e;
	vector<vector<int>> edges(v + 1);
	
	for(int i = 0 ; i < e ; i++) {
		int x , y; cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	vector<int> vis(v + 1 , 0);
	int count = 0;
	queue<pair<int , int>> q;
	q.push({1 , 1});
	vector<int> path(v + 1 , -1);
	int ans = -1;
	while(!q.empty()) {
		pair<int , int> pr = q.front();
		q.pop();
//		if(vis[pr.first]) continue;
		if(pr.first == v) {
			ans = pr.second;
			break;
		}
		vis[pr.first] = 1;
		for(auto next : edges[pr.first]) {
			if(vis[next]) continue;
			q.push({next , pr.second + 1});
			vis[next] = 1;
			path[next] = pr.first;
		}
	}

	if(ans == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	cout << ans << endl;
	int node = v;
	vector<int> res;
	while(node != 1) {
		res.push_back(node);
		node = path[node];
	}
	res.push_back(1);
	for(int i = ans - 1 ; i >= 0 ; i--) {
		cout << res[i] << " ";
	}
	cout << endl;
	
	
}
