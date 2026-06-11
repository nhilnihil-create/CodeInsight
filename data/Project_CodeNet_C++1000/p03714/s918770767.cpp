#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long

typedef pair<lint, lint> P;
const lint MOD = 1e9+7;
const lint INF = MOD * MOD;

int main(){
    int n; cin >> n;
    vector<lint> a;
    rep(i, n*3){
        lint x; cin >> x; a.push_back(x);
    }

    priority_queue<lint, vector<lint>, greater<lint> > pq;
    vector<lint> max_s, min_s;
    rep(i, n*2){
        if(i < n){
            pq.push(a[i]);
            if(i == 0) max_s.push_back(a[0]);
            else max_s.push_back(max_s[i-1] + a[i]); 
            continue;
        }
        pq.push(a[i]);
        max_s.push_back(max_s[i-1] + a[i] - pq.top());
        pq.pop();
    }
    priority_queue<lint, vector<lint>, less<lint> > pr;
    rep(i, n*2){
        int j = n*3 - i - 1;
        if(i < n){
            pr.push(a[j]);
            if(j == n*3 - 1) min_s.push_back(a[j]);
            else min_s.push_back(min_s[i-1] + a[j]); 
            continue;
        }
        pr.push(a[j]);
        min_s.push_back(min_s[i-1] + a[j] - pr.top());
        pr.pop();
    }
    lint ans = -INF;
    rep(i, n + 1){
        int j = i + n - 1, k = n*2 - i - 1;
        ans = max(ans, max_s[j] - min_s[k]);
    }
    cout << ans << endl;
}