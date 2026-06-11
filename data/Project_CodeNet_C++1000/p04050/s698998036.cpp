#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

ll a[maxn];
ll ans[maxn];
ll b[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0]<<endl<<1<<endl<<1;
        return 0;
    }
    if(m==1){
        cout<<a[0]<<endl<<2<<endl<<1<<' '<<a[0]-1<<endl;
        return 0;
    }
    sort(a,a+m);

    ll v=n%2;
    for(ll i=0;i<m;i++){
        v+=a[i]%2;
    }
    if(v>2){
        cout<<"Impossible";
        return 0;
    }

    if(n&1){
        for(ll i=0;i<m;i++){
            if(a[i]&1){
                ans[0]=a[i];
            }
        }
        ll cnt=1;
        for(ll i=0;i<m;i++){
            if(a[i]%2==0){
                ans[cnt++]=a[i];
            }
        }

        for(ll i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;

        cout<<m<<endl<<ans[0]+1<<' ';
        for(ll i=1;i+1<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<ans[m-1]-1;
    }else{
        if(v==0){
            ll cnt=0;
            for(ll i=0;i<m;i++){
                ans[cnt++]=a[i];
            }
            for(ll i=0;i<m;i++){
                cout<<ans[i]<<' ';
            }
            cout<<endl;

            cout<<m<<endl<<ans[0]+1<<' ';
            for(ll i=1;i+1<m;i++){
                cout<<ans[i]<<' ';
            }
            cout<<ans[m-1]-1;
        }else{
            ll cnt=0;
            for(ll i=0;i<m;i++){
                if(a[i]&1){
                    ans[cnt]=a[i];
                    cnt=m-1;
                }
            }
            if(ans[0]>ans[m-1])swap(ans[0],ans[m-1]);
            cnt=1;
            for(ll i=0;i<m;i++){
                if(a[i]%2==0){
                    ans[cnt++]=a[i];
                }
            }

            for(ll i=0;i<m;i++){
                cout<<ans[i]<<' ';
            }
            cout<<endl;
            if(ans[0]==1 && ans[m-1]==1){
                cout<<m-1<<endl;
                for(ll i=1;i+1<m;i++){
                    cout<<ans[i]<<' ';
                }
                cout<<2;
                return 0;
            }
            cout<<m<<endl<<ans[0]+1<<' ';
            for(ll i=1;i+1<m;i++){
                cout<<ans[i]<<' ';
            }
            cout<<ans[m-1]-1;
        }
    }
}
