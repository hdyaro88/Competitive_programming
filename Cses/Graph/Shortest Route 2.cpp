#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18 + 7;
signed main() {
	int n , m , q;
	cin >> n >> m >> q;
	vector<vector<int>> dist(n + 1 , vector<int> (n + 1 , inf));
	for(int i = 0 ; i < m ; i++) {
		int x , y , z;
		cin >> x >> y >> z;
		dist[x][y] = dist[y][x] = min(dist[x][y] , z);
		dist[x][x] = dist[y][y] = 0;
	}
	
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= n ; j++) {
			for(int k = 1 ; k <= n ; k++) {
				if(dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
				}
			}
		}
	}
 
	while(q--) {
		int x , y; cin >> x >> y;
		cout << (dist[x][y] == inf ? -1 : dist[x][y]) << endl;
	}
}
