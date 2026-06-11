#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n, m;
    cin >> n >> m;
    vi a(m), b(m), road(n);
    rep(i, m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        road[a[i]]++;
        road[b[i]]++;
    }

    rep(i, n){
        cout << road[i] << endl;
    }
    return 0;
}