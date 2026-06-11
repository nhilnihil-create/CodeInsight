#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,c,k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    sort(t.begin(),t.end());
    int j=0,cnt=0,ans=0,res=t[0];
    while(1){
        if(j==n-1){
            ++ans;
            break;
        }
        if(cnt==c){
            ++ans;
            cnt=0;
            res=t[j];
            continue;
        }
        if(res+k<t[j+1]){
            ++j;
            ++ans;
            cnt=0;
            res=t[j];
        }else{
            ++j;
            ++cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}   