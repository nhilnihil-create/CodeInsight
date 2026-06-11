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
    ll n;
    cin>>n;
    vector<ll> dp1(n,0),dp2(n,0);
    dp1[0]=dp2[0]=1;
    ll ans=(n-1)*(n-1)%MOD;
    if(1>=n-1){ans+=1;}
    else{ans+=2;}
    for(int i=1;i+1<n;i++){
        dp1[i]=dp1[i-1]+(i-3>=0?dp2[i-3]:0);
        dp1[i]%=MOD;
        dp2[i]=dp2[i-1]+dp1[i];
        dp2[i]%=MOD;
        ans+=dp1[i]*(n-1)%MOD*(n-1)%MOD;
        if(i+1==n-1){ans+=dp1[i]*(i+1)%MOD;}
        else{ans+=dp1[i]*(i+2)%MOD;}
        ans%=MOD;
    }
    ans+=((n-1-1>=0?dp1[n-1-1]:0)+(n-1-3>=0?dp2[n-1-3]:0))*n%MOD;
    ans%=MOD;
    cout<<ans<<endl;
    
    
    return 0;
}
