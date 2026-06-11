#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int k,t;
    cin >> k >> t;
    vector <int> a(t);
    rep(i,t){
        cin >> a[i];
    } 

    sort(a.begin(),a.end());
    int ans;
    ans=a[t-1]-1-(k-a[t-1]);
    if(ans<0){
        ans=0;
    }
    cout << ans << endl;
    

    return 0;
}