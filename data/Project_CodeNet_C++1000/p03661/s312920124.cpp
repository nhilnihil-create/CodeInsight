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
#include<complex>
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
    ll sum=0;
    for(int i=0;i<n;i++){cin>>a[i]; sum+=a[i];}
    ll ans=E;
    ll A=0;
    for(int i=0;i+1<n;i++){
        A+=a[i];
        ans=min(ans,abs(sum-2*A));
    }
    cout<<ans<<endl;
    
    
    return 0;
}
