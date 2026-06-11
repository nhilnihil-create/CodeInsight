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
#define P pair<double,double>
double pi = 3.141592653589793;
using namespace std;
//ここから始めよう
signed main(){
    int n;cin>>n;int ans=0;
    int mini=1;
    rep(i,0,n){
        int a;cin>>a;
        ans+=(a-1)/mini;
        if(i==0||a==mini)mini++;
    }cout<<ans<<endl;
    return 0;
}