#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define max0(a,b,c) max(max(a,b),c)
#define min0(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
using Graph = vector<vector<int>>;
typedef long long lint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<ull> ulvec;
typedef vector<double> dvec;
typedef vector<pair<int,int>> pvec;
typedef vector<pair<ll,ll>> plvec;
typedef vector<tuple<ll,ll,ll>> tvec;
typedef vector<string> svec;

int main(){
    int a,b;
    cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}