#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007LL;
const double INF=1000000000;
const int MAX=100001;
int main(){
    ll n,l,t;
    cin>>n>>l>>t;
    ll w[100010],x[100010];
    vector<ll> v;
    for(int i=0;i<n;i++){
        cin>>x[i]>>w[i];
        if(w[i]==1){
            v.push_back((x[i]+t)%l);
        }else{
            v.push_back(((x[i]-t)%l+l)%l);
        }
    }
    ll c=0;
    for(int i=0;i<n;i++){
        if(w[i]==1){
            c+=(x[i]+t)/l;
        }else{
            c-=(t-x[i]-1+l)/l;
        }
    }
    c=(c%n+n)%n;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[(i+c)%n]<<endl;
    }   
    return 0;
}

                           
