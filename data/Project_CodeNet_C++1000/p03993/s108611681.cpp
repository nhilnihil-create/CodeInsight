#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    int cnt = 0;
    int n; cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];

    for(int i = 0; i < n; i++){
        if(a[a[i]-1] == i+1){ cnt++; }
    }

    put(cnt/2);
}