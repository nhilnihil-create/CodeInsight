//E.H//
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
typedef long long ll;
ll n,arr[100005];
ll d[100005],sum;;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    arr[n+1]=arr[1];
    for(ll i=1;i<=n;i++){
        d[i]=arr[i+1]-arr[i];
    }
    if(sum%(n*(n+1)/2) == 0){
        ll k=sum/(n*(n+1)/2);
        for(ll i=1;i<=n;i++){
            if((k-d[i]) % n !=0 || k-d[i]<0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
}