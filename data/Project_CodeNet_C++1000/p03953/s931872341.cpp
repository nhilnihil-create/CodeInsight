#include<bits/stdc++.h>
#define reg register
#define ll long long
#define maxn 200001
using namespace std;
inline ll  read() {
    reg ll s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
ll n, x[maxn], m, k, d[maxn], cha[maxn], sum[maxn], belong[maxn];
ll nxt[maxn], w[maxn], a[maxn], vis[maxn], f[maxn], cnt;
vector<ll> Q[maxn];
int main()
{
    n = read();
    for(int i = 1; i <= n; i++) x[i] = read(),cha[i] = x[i] - x[i - 1];
    m = read(); k = read(); 
    for(int i = 1; i <= m; i++) a[i] = read();
    for(int j = 1; j <= n; j++) d[j] = j;
    for(int i = 1; i <= m; i++)
        swap(d[a[i]], d[a[i] + 1]);
    for(int i = 1; i <= n; i++) nxt[d[i]] = i;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
           int p = i;  cnt++;
            while(!vis[p]) {
                Q[cnt].push_back(p); vis[p] = 1;
                sum[cnt]++; belong[p] = cnt; f[p] = sum[cnt] - 1;
                p = nxt[p];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int p = k % sum[belong[i]];
        nxt[i] = Q[belong[i]][(f[i] + p) % sum[belong[i]]]; 
        w[nxt[i]] = i;
    }
    for(int i = 1; i <= n; i++) a[i] = cha[w[i]];
    for(int i = 1; i <= n; i++)
        a[i] += a[i - 1], printf("%lld\n", a[i]);
}
