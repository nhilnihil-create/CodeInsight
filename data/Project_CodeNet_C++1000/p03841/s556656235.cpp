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
    set<ll> S;
    ll n;
    cin>>n;
    vector<ll> ans(n*n,-1);
    for(int i=0;i<n*n;i++){S.insert(i);}
    vector<pll> A(n);
    for(int i=0;i<n;i++){cin>>A[i].F; A[i].S=i+1; A[i].F--;}
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++){
        ll cnt=1;
        for(auto I=S.begin();I!=S.end() && (*I)<A[i].F && cnt<A[i].S;){
            ans[(*I)]=A[i].S;
            I=S.erase(I);
            cnt++;
        }
        if(cnt!=A[i].S){cout<<"No"<<endl; return 0;}
        ans[A[i].F]=A[i].S;
        S.erase(A[i].F);
    }
    
    reverse(A.begin(),A.end());
    for(int i=0;i<n;i++){
        if(A[i].S==n){continue;}
        ll cnt=0;
        auto I=S.end();
        --I;
        for(;cnt<n-A[i].S && *I>A[i].F;--I,cnt++){
            ans[*I]=A[i].S;
            I=S.erase(I);
            if(I==S.begin()){cnt++; break;}
        }
        if(cnt!=n-A[i].S){cout<<"No"<<endl; return 0;}
    }
    
    cout<<"Yes"<<endl;
    for(int i=0;i<n*n;i++){
        cout<<ans[i];
        if(i+1!=n*n){cout<<" ";}
    }
    cout<<endl;
    
    
    return 0;
}
