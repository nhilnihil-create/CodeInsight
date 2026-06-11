#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
#define F first
#define S second
#define MK make_pair
const ll E=1e17+7;





int main(){
    ll n;
    cin>>n;
    vector<ll> a;
    for(int i=0;i<3*n;i++){
        ll b;
        cin>>b;
        a.push_back(b);
    }
    vector<ll> front,back;
    priority_queue<ll,vector<ll>,greater<ll>> f;
    priority_queue<ll> b;
    ll sum=0;
    for(ll i=0;i<n;i++){
        f.push(a[i]);
        sum+=a[i];
    }
    front.push_back(sum);
    for(ll i=n;i<2*n;i++){
        sum+=a[i];
        f.push(a[i]);
        sum-=f.top();
        f.pop();
        front.push_back(sum);
    }
    sum=0;
    for(ll i=3*n-1;i>=2*n;i--){
        b.push(a[i]);
        sum+=a[i];
    }
    back.push_back(sum);
    for(ll i=2*n-1;i>=n;i--){
        sum+=a[i];
        b.push(a[i]);
        sum-=b.top();
        b.pop();
        back.push_back(sum);
    }
    reverse(back.begin(),back.end());
    ll ans=-E;
    for(int i=0;i<back.size();i++){
        ans=max(ans,front[i]-back[i]);
    }
    cout<<ans<<endl;
    
    
    return 0;
}

