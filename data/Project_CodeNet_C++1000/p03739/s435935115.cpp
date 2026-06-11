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
    int n;
    cin>>n;
    vector<ll> a;
    vector<ll> b;
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        a.pb(k);
        b.pb(k);
    }
    ll evenans=0; // even +ve 0index
    ll oddans=0; // odd +ve

    for(int i=0;i<n;i+=2){
        if(a[i]<0){
            evenans-=a[i];
            a[i]=0;
        }
    }
    for(int i=1;i<n;i+=2){
        if(a[i]>0){
            evenans+=a[i];
            a[i]=0;
        }
    }
    ll count=0;
    for(int i=0;i<=n-1;i++){
        count+=a[i];
        if((i&1)==0){
            if(count<=0){
                evenans=evenans-count+1;
                count=1;
            }
        }
        else{
            if(count>=0){
                evenans=evenans+count+1;
                count=-1;
            }
        }
    }



    for(int i=0;i<n;i+=2){
        if(b[i]>0){
            oddans+=b[i];
            b[i]=0;
        }
    }
    for(int i=1;i<n;i+=2){
        if(b[i]<0){
            oddans-=b[i];
            b[i]=0;
        }
    }
    count=0;
    for(int i=0;i<=n-1;i++){
        count+=b[i];
        if((i&1)==1){
            if(count<=0){
                oddans=oddans-count+1;
                count=1;
            }
        }
        else{
            if(count>=0){
                oddans=oddans+count+1;
                count=-1;
            }
        }
    }
    //cout<<oddans<<' '<<evenans<<endl;
    cout<<min(oddans,evenans)<<endl;
    return 0;
}
