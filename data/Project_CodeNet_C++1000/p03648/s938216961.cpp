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
signed main(){
    int n;cin>>n;
    cout<<50<<endl;
    int a[55]={};
    for(int i=49;i>=0;i--){
        a[i]=49-i;
    }
    rep(i,0,n%50){
        a[i]=50;
    }
    rep(i,0,50){
        a[i]+=n/50;
        cout<<a[i]<<" ";
    }cout<<endl;
    return 0;
}
