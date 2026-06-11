#include<bits/stdc++.h>
#include<queue>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n+1; i++)
#define repr(i,n) for(int i=n-1; i>=0; i--)
#define repr1(i,n) for(int i=n; i>0; i--)
#define FOR(i,j,n) for(int i=j; i < n; i++)

int main(){
    int n;
    cin >> n;

    vector<int> a(n+1);
    a[0] = 0;
    int ans = 0;

    rep1(i,n) cin >> a[i];

    rep1(i,n){
        if(a[a[i]] == i) ans++;
    }

    cout << ans/2 << endl;
}