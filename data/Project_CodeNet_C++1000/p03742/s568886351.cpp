#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
int a,b;
signed main(){
    a=read(),b=read();
    printf(abs(a-b)<=1?"Brown\n":"Alice\n");
    return 0;
}

