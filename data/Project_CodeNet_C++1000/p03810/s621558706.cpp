#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<60;
const double eps=1e-5;
const ll MOD=1000000007LL;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    ll n;cin>>n;
    vector<ll> a(n+10);
    int co=0;
    ll sum=0;
    int id;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]%2){
            co++;
            id=i;
        }
    }
    bool f=false;
    int k=1;
    while(a[id]>1&&co==1&&n%2){
        a[id]--;
        ll g=a[0];
        for(int i=1;i<n;i++){
            g=__gcd(g,a[i]);
        }
        co=0;
        for(int i=0;i<n;i++){
            a[i]/=g;
            if(a[i]%2){
                id=i;
                co++;
            }
        }
        if(k%2){
            if(co%2&&(co>1||a[id]==1)){
                f=true;
                break;
            }else if(co%2==0){
                break;
            }
        }else{
            if(co%2&&(co>1||a[id]==1)){
                break;
            }else if(co%2==0){
                f=true;
                break;
            }
        }
        k++;
    }
    if(n==1){
        cout<<"Second"<<endl;
        return 0;
    }
    if((sum-n)%2LL>0||f){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}
