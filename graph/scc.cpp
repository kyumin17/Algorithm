#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define MAX 10000

using namespace std;

vector<vector<int>> v(MAX), v_rev(MAX);
vector<bool> vis(MAX);
vector<int> num(MAX);
vector<int> order;
vector<vector<int>> v_scc;

void dfs(int n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (int i: v[n]) dfs(i);
    order.push_back(n);
}

void dfs_rev(int n, int t) {
    if (num[n]) return;
    num[n] = t;
    for (int i: v_rev[n]) dfs_rev(i, t);
}

void scc(int n) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    reverse(all(order));

    int cnt = 0;
    for (int i: order) {
        if (!num[i]) dfs_rev(i, ++cnt);
    }

    v_scc.resize(cnt);
    for (int i = 1; i <= n; i++) {
        v_scc[num[i]-1].push_back(i);
    }
}