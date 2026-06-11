#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,m,a[maxn];

int main() {
    read(n),read(m);
    for(int i=1,x,y;i<=m;i++) read(x),read(y),a[x]++,a[y]++;
    for(int i=1;i<=n;i++) if(a[i]&1) return puts("NO"),0;
    puts("YES");
    return 0;
}
