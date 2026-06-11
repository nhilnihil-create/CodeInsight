#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> P;
typedef pair<double,double> P_f;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define bitrep(bit,n) for(int bit=0; bit<=(1<<n);bit++)
#define MAX 100100
#define MAX_N 200100
#define MAX_T 2001001
#define SENTINEL 20010010010
#define NIL -1
static const int INF = 1 << 29;
const ll INFTY = 1LL<<50;
const int MOD=1e9+7;
LL x;
int main(){
    cin>>x;
    LL remain=x%11;
    LL quot=x/11;
    LL ans=quot*2;
    if(remain<=6 && remain!=0)ans++;
    else if(remain!=0)ans+=2;
    cout<<ans<<endl;
}