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

bool dp[5001][5001];
int n,k;
vector<ll> a;

int dpxy(ll y,ll x){    // cant use a[x] to make sum y
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(x!=0){
        dp[0][a[0]]=1;
    }
    else{
        dp[1][a[1]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            if(dp[i-1][j]==1){
                dp[i][j]=1;
                if(j+a[i]<k && i!=x){
                    dp[i][j+a[i]]=1;
                }
            }
        }
    }
    int ans=0;
    for(int i=y;i<k;i++){
        if(dp[n-1][i]==1){
            ans=1;
            break;
        }
    }
    return ans;
}

// hitsuyou (dp=1) ;hitsuyoudenai (dp=0)   max unnecessary
int binarysearch(int p,int q){
    int lo=p,hi=q;
    int med=lo+hi;
    med>>=1;
    if(hi>lo+1){
        ll y=k-a[med];
        if(y>=0){
            if(dpxy(y,med)==0){  // unnecessary
                binarysearch(med,hi);
            }
            else{
                binarysearch(lo,med);
            }
        }
        else{
            binarysearch(lo,med);
        }
    }
    else{
        ll y=k-a[med];
        if(y>=0){
            if(dpxy(y,med)==0){  // unnecessary
                return med;
            }
            else{
                return med-1;
            }
        }
        else{
            return med-1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    ll sum=0;
    for(ll i=0;i<n;i++){
        ll c;
        cin>>c;
        sum+=c;
        a.pb(c);
    }
    sort(a.begin(),a.end());
    ll count=0;
    if(sum>=k && n>1){
        count=binarysearch(0,n-1);
        count+=1;
    }
    else if(n==1){
        count=0;
    }
    else{
        count=n;
    }
    cout<<count<<endl;
    return 0;
}
