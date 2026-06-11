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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<ll> arr[51];
    arr[1].pb(1);
    arr[1].pb(1);
    arr[2].pb(1);
    arr[2].pb(2);
    arr[2].pb(1);
    for(int i=3;i<=50;i++){
        arr[i].pb(1);
        for(int j=0;j<=i-2;j++){
            ll k=arr[i-1][j]+arr[i-1][j+1];
            arr[i].pb(k);
        }
        arr[i].pb(1);
    }
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        v.pb(k);
    }
    sort(v.begin(),v.end());

    ld count=0;

    int countbig=1;
    for(int i=n-2;i>=0;i--){
        if(v[i]!=v[n-1]){
            break;
        }
        else{
            countbig+=1;
        }
    }
    if(countbig>=a){
            //cout<<"case1"<<endl;
        cout<<v[n-1]<<endl;
        ll ans=0;
        for(int i=a;(i<=b) && (i<=countbig);i++){
            ans+=arr[countbig][i];
        }
        cout<<ans<<endl;
    }
    else{
        //cout<<"case2"<<endl;
        ll countsmall=0,counta=0,countx=0;
        for(int i=n-1;i>n-a-1;i--){
            count+=v[i];
            if(v[i]==v[n-a]){
                counta+=1;          // how many needed
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]==v[n-a]){
                countsmall+=1;      // how many are there
            }
        }
        count/=a;
        cout<<setprecision(9)<<count<<endl;
        for(int i=n-1;i>=0;i--){
            if(v[i]==v[n-a]){
                break;
            }
            else{
                countx+=1;
            }
        }
        a-=countx;
        b-=countx;
        ll ans=0;
        ans+=arr[countsmall][a];
        cout<<ans<<endl;
    }
    return 0;
}
