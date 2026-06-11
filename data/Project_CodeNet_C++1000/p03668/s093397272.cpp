#include <bits/stdc++.h>
#define y1 __zzd001
using namespace std;
typedef long long LL;
LL read(){
    LL x=0;
    char ch=getchar();
    while (!isdigit(ch))
        ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
const int N=100005;
int n,sg[N];
vector <int> e[N];
void solve(int x,int pre){
    sg[x]=0;
    for (auto y : e[x])
        if (y!=pre){
            solve(y,x);
            sg[x]^=sg[y]+1;
        }
}
int main(){
    n=read();
    for (int i=1;i<n;i++){
        int x=read(),y=read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1,0);
    puts(sg[1]?"Alice":"Bob");
    return 0;
}