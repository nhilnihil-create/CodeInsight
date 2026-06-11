#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
double pi = 3.141592653589793;
using namespace std;
//ここから始めよう
int solve(int a,int b,int c){
    return (a/2)*4+(b/2)*4+(c/2)*4;
}
signed main(){
    int a,b,c,d,e,f,g;cin>>a>>b>>c>>d>>e>>f>>g;int ans=0;ans+=2*b;
    if(a>=1&&d>=1&&e>=1)ans+=max(solve(a,d,e),solve(a-1,d-1,e-1)+6);
    else ans+=solve(a,d,e);
    cout<<ans/2<<endl;
    return 0;
}