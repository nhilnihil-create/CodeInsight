#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1000000007;
const long long inf = 1e18;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    priority_queue <int, vector<int>, greater<int>>  pq;
    priority_queue <int>  pq2;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<3*n;i++){
        int k;
        cin>>k;
        v.pb(k);
    }
    map<int,ii> score;
    for(int i=n-1;i<2*n;i++){
        score[i]=mp(0,0);
    }
    // score[i]= take until ith for first half i+1th onwards for second half
    ll l=0;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
        l+=v[i];
    }
    score[n-1].fi=l;
    for(int i=n;i<2*n;i++){
        pq.push(v[i]);
        l+=v[i];
        l-=pq.top();
        pq.pop();
        score[i].fi=l;
    }

    ll r=0;
    for(int i=3*n-1;i>=2*n;i--){
        pq2.push(v[i]);
        r+=v[i];
    }
    score[2*n-1].se=r;
    for(int i=2*n-1;i>=n;i--){
        pq2.push(v[i]);
        r+=v[i];
        r-=pq2.top();
        pq2.pop();
        score[i-1].se=r;
    }
    ll ans=score[n-1].fi-score[n-1].se;
    for(int i=n-1;i<2*n;i++){
        if(score[i].fi-score[i].se>ans){
            ans=score[i].fi-score[i].se;
        }
    }
    cout<<ans<<endl;
    return 0;
}
