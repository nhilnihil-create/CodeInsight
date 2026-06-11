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

ll arr[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int k=i;
        while((k&1)==0){
            k>>=1;
            arr[2]+=1;
        }
        for(int j=3;j<=sqrt(k);j++){
            while((k%j)==0){
                arr[j]+=1;
                k/=j;
            }
        }
        if(k>1){
            arr[k]+=1;
        }
    }
    ll ans=1;
    for(int i=2;i<=n;i++){
        if(arr[i]>0){
            arr[i]+=1;
            ans*=arr[i];
            ans=ans%1000000007;
        }
    }
    cout<<ans<<endl;
    return 0;
}
