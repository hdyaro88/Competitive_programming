#include<bits/stdc++.h>
using namespace std;

int main() {
	int n , m;
	cin >> n >> m;
	vector<int> in(n + 1 , 0);
	vector<vector<int>> edges(n + 1);
	
	for(int i = 0 ; i < m ;i++) {
		int x , y;
		cin >> x >> y;
		edges[x].push_back(y);
		in[y]++;
	}
	
	queue<int> q;
	
	for(int i = 1 ; i <= n ; i++) {
		if(!in[i]) {
			q.push(i);
		}
	}
	
	int cnt = 0;
	
	vector<int> ord;
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		for(auto next : edges[node]) {
			in[next]--;
			if(!in[next]) {
				q.push(next);
			}
		}
		
		ord.push_back(node);
	}
	
	if(ord.size() != n) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
	for(auto el : ord) {
		cout << el << " ";
	}
	cout << endl;
		
	}
	
	
}
