#include <bits/stdc++.h>
using ll = long long;
#define pll pair<ll, ll>

using namespace std;

int ccw(pll a, pll b, pll c) {
	ll x = (b.first - a.first) * (c.second - b.second) - (c.first - b.first) * (b.second - a.second);

    if (x > 0) return 1;
    else if (x == 0) return 0;
    else return -1;
}

bool intersect(pair<pll, pll> l1, pair<pll, pll> l2) {
    pll s1 = l1.first, e1 = l1.second, s2 = l2.first, e2 = l2.second;
    
    int c1 = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    int c2 = ccw(s2, e2, s1) * ccw(s2, e2, e1);

    if (c1 == 0 && c2 == 0) return min(s2, e2) <= max(s1, e1) && min(s1, e1) <= max(s2, e2);
    
    return c1 <= 0 && c2 <= 0;
}