#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int a,b,c,flag=0;
scanf("%d %d %d",&a,&b,&c);
map<int,int>cycle;
for(int i=1;i<=105;++i){
    int res=(a*i)%b;
    if(cycle[res]){
        break;
    }
    if(res==c){
        flag=1;
        break;
    }
    cycle[res]=1;
}
(flag)?printf("YES"):printf("NO");


    return 0;
}
