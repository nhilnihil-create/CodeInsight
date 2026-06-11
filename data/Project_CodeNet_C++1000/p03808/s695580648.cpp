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
    vector<ll> a(n);
    ll k=n*(n+1)/2;
    ll sum=0;
    for(auto &i:a){cin>>i; sum+=i;}
    if(sum%k){cout<<"NO"<<endl; return 0;}
    sum/=k;
    vector<ll> dp(n,0);
    for(int i=1;i<n;i++){
        ll k=a[i-1]+sum-a[i];
        if(k<0 || k%n){cout<<"NO"<<endl; return 0;}
        dp[i]=k/n;
    }
    k=a.back()+sum-a[0];
    if(k<0 || k%n){cout<<"NO"<<endl; return 0;}
    dp[0]=k/n;
    sum=0;
    ll count=0;
    for(int i=0;i<n;i++){
        count+=dp[i];
        sum+=count;
        a[i]-=sum;
    }
    sum=0;
    count=0;
    for(ll i=n-2;i>=0;i--){
        sum-=count;
        sum+=n*dp[i+1];
        count+=dp[i+1];
        a[i]-=sum;
    }
    for(auto &i:a){
        if(i){cout<<"NO"<<endl; return 0;}
    }
    cout<<"YES"<<endl;
    
    
    return 0;
}

