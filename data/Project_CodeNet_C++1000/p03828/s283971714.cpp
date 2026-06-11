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
int n;
int D[1010];
int main(){
    memset(D,0,sizeof(D));
    cin>>n;
    int temp=1;
    for(int i=1;i<=n;i++){
        temp=i;
        for(int j=2;j<=temp;j++){
            while(temp%j==0){
                D[j]++;temp/=j;
            }

            
        }
    }
    LL ans=1;
    for(int i=2;i<=1000;i++){
        ans=ans*(D[i]+1)%MOD;
    }
    cout<<ans<<endl;

}