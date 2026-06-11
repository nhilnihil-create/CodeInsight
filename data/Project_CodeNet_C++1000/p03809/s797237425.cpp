#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<vector<ll>> v(100010);
ll a[100010];
bool used[100010];

bool pos = true;

ll dfs(ll p){
    used[p] = true;

    bool leaf = true;
    ll sum = 0, M = 0;
    for(auto i:v[p]){
        if(!used[i]){
            ll t = dfs(i);
            leaf = false;
            M = max(M,t);
            sum += t;
        }
    }
    if(leaf) return a[p];

    ll mxp = min(sum - M,sum/2);

    if(sum<a[p] || a[p] < sum - mxp){
        cout << "NO\n";
        exit(0);
    }
    ll ret = a[p] - (sum - a[p]);
    //if( (sum-a[p]) <= min(sum - M,sum/2) ){
        return ret;
    //}
    // pos = false;
    // return -1;
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    

    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    int root=0;
    for(ll i=0;i<n-1;i++){
        ll r,b;
        cin>>r>>b;
        r--,b--;
        v[r].push_back(b);
        v[b].push_back(r);
        if(v[r].size()>1) root = r;
        if(v[b].size()>1) root = b;
    }

    if(n==2 && a[0]==a[1]){
        cout<<"YES"<<endl;
        return 0;
    }
    else if(n==2) {
        cout<<"NO"<<endl;
        return 0;
    }
    

    ll r = dfs(root);

    if(pos && r==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
