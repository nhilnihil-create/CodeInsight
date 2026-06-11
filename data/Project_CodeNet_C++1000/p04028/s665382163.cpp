#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int MOD=1e9+7;
const int MAXN=5005;
typedef long long ll;

int n,m;
ll d[MAXN][MAXN];

int main(){
    string s;
    scanf("%d",&n);
    cin >> s; m=s.length();
    d[0][0]=1;
    for(int j=1;j<=n;j++)
        for(int i=0;i<=n;i++){
            if(i!=n) d[i][j]+=2ll*d[i+1][j-1];
            if(i!=0) d[i][j]+=d[i-1][j-1];
            if(i==0) d[i][j]+=d[i][j-1];
            d[i][j]%=MOD;
        }
    printf("%lld",d[m][n]);
}
