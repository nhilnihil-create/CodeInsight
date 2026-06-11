#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> b;
    rep(i,n){
        if(i % 2 == 0) b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if(n % 2 == 1)reverse(ALL(b));
    rep(i,n){
        int tmp = b.front();
        b.pop_front();
        printf("%d%c", tmp, i==n-1 ? '\n' : ' ');
    }
}