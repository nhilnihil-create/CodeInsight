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
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;




int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> count(n,0);
    ll mx=0;
    ll mi=E;
    for(int i=0;i<n;i++){
        cin>>a[i];
        count[a[i]]++;
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    if(count[mi]!=(mx&1?2:1) || mi!=(mx+1)/2){cout<<"Impossible"<<endl; return 0;}
    for(ll i=mx;i>mi;i--){
        if(count[i]<2){cout<<"Impossible"<<endl; return 0;}
    }
    cout<<"Possible"<<endl;
    
    
    
    
    return 0;
}
