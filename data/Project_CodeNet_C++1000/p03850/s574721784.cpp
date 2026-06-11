#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define ll long long
using namespace std;
const long long N=1e5+10,M=3e5+30,LEN=50;
const int Mod=10007;
const long double EPS=1e-7;
const long long MAX=1e18;
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n,a;
long long f[N][5];
int main(){
    //freopen("problem.in","r",stdin);
    //freopen("problem.ans","w",stdout);
    scanf("%d",&n);
    f[0][0]=0;
    f[0][1]=f[0][2]=-MAX;
    for(int i=1;i<=n;i++){
    	a=read();
    	f[i][0]=max(f[i-1][0],f[i-1][1]);
    	f[i][1]=max(f[i-1][1],f[i-1][2]);
    	f[i][2]=f[i-1][2];
    	f[i][0]+=a;
    	f[i][1]-=a;
    	f[i][2]+=a;
    	if(a<0){
    		f[i][2]=max(f[i][2],f[i][1]);
    		f[i][1]=max(f[i][1],f[i][0]);
    	}
    }
    printf("%lld\n",max(f[n][0],max(f[n][1],f[n][2])));
    return 0;
}