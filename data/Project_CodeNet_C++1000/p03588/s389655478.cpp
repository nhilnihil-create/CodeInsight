#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    rep(i,0,n){
        int r,s;
        cin>>r>>s;
        vec[i]=make_pair(r,s);
    }
    sort(all(vec),greater<pair<int,int>>());
    
    cout<<vec[0].first+vec[0].second<<endl;
}
