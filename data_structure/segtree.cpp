#include <bits/stdc++.h>
using ll = long long;
#define MAX 1000000

using namespace std;

vector<ll> arr(MAX), v(4 * MAX);

ll init(int n, int s = 1, int e = MAX) {
	if (s == e) return v[n] = arr[s];
	int m = (s + e) / 2;
	return v[n] = init(2 * n, s, m) + init(2 * n + 1, m + 1, e);
}

ll update(int i, ll x, int n, int s = 1, int e = MAX) {
	if (e < i || i < s) return v[n];
	if (s == e && s == i) return v[n] = x;
	int m = (s + e) / 2;
	return v[n] = update(i, x, 2 * n, s, m) + update(i, x, 2 * n + 1, m + 1, e);
}

ll query(int qs, int qe, int n, int s = 1, int e = MAX) {
	if (e < qs || qe < s) return 0;
	if (qs <= s && e <= qe) return v[n];
	int m = (s + e) / 2;
	return query(qs, qe, 2 * n, s, m) + query(qs, qe, 2 * n + 1, m + 1, e);
}