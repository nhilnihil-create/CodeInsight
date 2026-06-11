#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
#define chmax(a,b) a=max(a,b);
ll a[N],n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,greater<ll>());
    ll s=-1;
    for(ll i=0;i<n;i++){
        if(i<a[i])chmax(s,i);
    }
    bool vl=(a[s]-s)%2==1;
    ll t=-1;
    for(ll i=0;i<n;i++){
     if(s<a[i])chmax(t,i);   
    }
    bool vr=(t-s)%2==0;
    cout<<((vl&vr)?"Second":"First")<<endl;
 return 0;   
}