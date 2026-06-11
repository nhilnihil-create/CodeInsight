#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>
#include <cmath>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rip(i,n,0){
        cin >> a[i];
    }
    vector<vector<ll>> da(n,vector<ll>(n)); // da[i][j] i番目のjこ後ろまで見る
    rip(i,n,0){
        da[i][0]=a[i];
        rip(j,n,1){
            da[(i+j)%n][j]=min(da[(i+j-1)%n][j-1],a[(i+j)%n]);
        }
    }
    ll ans=LLONG_MAX;
    rip(i,n,0){
        ll memo=0;
        rip(j,n,0){
            memo+=da[j][i];
        }
        memo+=(ll) x*i;
        ans=min(ans,memo);
    }
    cout << ans << endl;
}