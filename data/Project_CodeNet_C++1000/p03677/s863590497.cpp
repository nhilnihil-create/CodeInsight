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
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
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
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(auto &I:a){cin>>I; I--;}
    vector<pll> A(3*m,{0,0});
    ll ans=0;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            ans+=a[i]+m-a[i-1];
            A[a[i-1]].S+=1;
            A[a[i]+m].S-=1;
            A[a[i]+m].F-=a[i]+m-a[i-1];
            A[a[i-1]+m].S+=1;
            A[a[i]+m*2].S-=1;
            A[a[i]+m*2].F-=a[i]+m-a[i-1];
        }
        else{
            ans+=a[i]-a[i-1];
            A[a[i-1]].S+=1;
            A[a[i]].S-=1;
            A[a[i]].F-=abs(a[i-1]-a[i]);
            A[a[i-1]+m].S+=1;
            A[a[i]+m].S-=1;
            A[a[i]+m].F-=a[i]-a[i-1];
            A[a[i-1]+m*2].S+=1;
            A[a[i]+m*2].S-=1;
            A[a[i]+m*2].F-=a[i]-a[i-1];
        }
    }
    ll mx=0;
    ll cnt=0;
    ll sum=0;
    for(int i=0;i<3*m;i++){
        sum+=cnt;
        sum+=A[i].F;
        //cout<<" "<<sum;
        cnt+=A[i].S;
        mx=max(mx,sum);
    }
    //cout<<endl;
    cout<<ans-mx<<endl;
    
    
    return 0;
}
