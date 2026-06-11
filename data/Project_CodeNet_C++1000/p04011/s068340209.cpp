//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll n,k,x,y; cin>>n>>k>>x>>y;
    if(n<=k)cout<<n*x<<endl;
    else cout<<(n-k)*y+k*x<<endl;
}



























































































