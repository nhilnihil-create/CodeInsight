#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i <= k;++i)
#define repp(i,j,k) for(int i = j;i >= k;--i)
#define rept(i,x) for(int i = linkk[x];i;i = e[i].n)
#define P pair<int,int>
#define Pil pair<int,ll>
#define Pli pair<ll,int>
#define Pll pair<ll,ll>
#define pb push_back 
#define pc putchar
#define mp make_pair
#define file(k) memset(k,0,sizeof(k))
#define ll long long
int rd()
{
    int sum = 0;char c = getchar();bool flag = true;
    while(c < '0' || c > '9') {if(c == '-') flag = false;c = getchar();}
    while(c >= '0' && c <= '9') sum = sum * 10 + c - 48,c = getchar();
    if(flag) return sum;
    else return -sum;
}
int n,m;
int a[110];
int main()
{
    n = rd();m = rd();
    int cnt = 0,pos1,pos2;
    rep(i,1,m)
    {
        a[i] = rd();
        if(a[i]%2 == 1)
        {
            if(!cnt) cnt++,pos1 = i;
            else cnt++,pos2 = i;
        }
    }
    if(cnt > 2) printf("Impossible");
    else
    if(m == 1)
    {
        if(a[1] == 1) printf("%d\n1\n%d",a[1],a[1]);
        else printf("%d\n2\n1 %d\n",a[1],a[1]-1);
    }
    else
    {
        if(cnt>0) swap(a[1],a[pos1]);
        if(cnt>1) swap(a[m],a[pos2]);
        rep(i,1,m) printf("%d ",a[i]);printf("\n");
        a[1]++;a[m]--;
        if(a[m] == 0) m--;
        printf("%d\n",m);
        rep(i,1,m) printf("%d ",a[i]);
    }
    return 0;
}