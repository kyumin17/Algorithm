#include <bits/stdc++.h>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define MAX 10000
#define INF 1e9

using namespace std;

vector<vector<pii>> v(MAX);
vector<int> dist(MAX);

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill(all(dist), INF);
    pq.push({dist[s] = 0, s});

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();
        int fr = cur.second;
        
        if (cur.first != dist[fr]) continue;
        
        for (int i = 0; i < v[fr].size(); i++) {
            int to = v[fr][i].first;
            int d = v[fr][i].second;

            if (dist[to] > dist[fr] + d) {
                pq.push({dist[to] = dist[fr] + d, to});
            }
        }
    }
}