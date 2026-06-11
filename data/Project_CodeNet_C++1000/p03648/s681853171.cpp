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
    ll k;
    cin>>k;
    ll N=50;
    vector<ll> a(N,N-1);
    ll X=(k+N-1)/N;
    for(int i=0;i<N;i++){a[i]+=X;}
    X*=N;
    ll w=0;
    for(int i=0;X>k;i++,X--,w++){a[i]-=N+1;}
    for(auto &I:a){I+=w;}
    cout<<N<<endl;
    for(int i=0;i<N;i++){
        cout<<a[i];
        if(i+1!=N){cout<<" ";}
    }
    cout<<endl;
    
    
    return 0;
}
