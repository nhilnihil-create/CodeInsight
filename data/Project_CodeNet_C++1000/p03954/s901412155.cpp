#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long 
#define ret return
#define PB push_back
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define pll pair <long long ,  long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);

const int maxn = 2e5 + 10 , INF = 1e9 + 10;
int a[maxn] , color[maxn] , n;

bool check(int k) {
    fill(color , color + maxn , 0); 
    for (int i = 1; i <= 2 * n - 1; ++i) {
        if(a[i] >= k) {
            color[i] = 1;
        }
        else {
            color[i] = 0;
        }
    }
    if((color[n] == color[n - 1]) || (color[n] == color[n + 1])) {
        return color[n];
    }
    ll dis1 = INF , dis2 = INF , c1 = -1 , c2 = -1;
    for (int i = n - 1; i >= 1; --i) {
        if(color[i] == color[i + 1]) {
            dis1 = n - i;
            c1 = color[i];
            break;
        }
    }
    for (int i = n + 1; i <= 2 * n - 1; ++i) {
        if(color[i] == color[i - 1]) {
            dis2 = i - n;
            c2 = color[i];
            break;
        }
    }
    if(dis1 == INF && dis2 == INF) {
        return color[1];
    }
    if(dis1 < dis2) {
        return c1;
    }
    return c2;
}

int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        cin >> a[i];
    }
    int l = 1 , r = 2 * n;
    while(l < r - 1) {
        int m  = (l + r) / 2;
        if(check(m) == 0) {
            r = m;
        }
        else{ 
            l = m;
        }
    }
    cout << l << endl;
}