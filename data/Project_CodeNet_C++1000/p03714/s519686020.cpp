#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const lint inv = MOD - 2;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    int n;
    cin >> n;
    vector<lint> a(n*3);
    rep(i, n*3){
        cin >> a[i];
    }
    vector<lint> f(n+1);
    priority_queue<lint, vector<lint>, greater<lint> > front;
    lint fsum = 0;
    rep(i, n){
        front.push(a[i]);
        fsum += a[i];
    }
    f[0] = fsum;
    REP(i, n, n*2){
        front.push(a[i]);
        fsum += a[i];
        fsum -= front.top();
        front.pop();
        f[i-n+1] = fsum;
    }
    vector<lint> b(n+1);
    priority_queue<lint> back;
    lint bsum = 0;
    REP(i, n*2, n*3){
        back.push(a[i]);
        bsum += a[i];
    }
    b[n] = bsum;
    for(lint i = n*2-1 ; i >= n ; i--){
        back.push(a[i]);
        bsum += a[i];
        bsum -= back.top();
        back.pop();
        b[i-n] = bsum;
    }
    lint ans = f[n] - b[n];
    rep(i, n){
        ans = max(ans, f[i] - b[i]);
    }
    cout << ans << endl;
    return 0;
}