#include<bits/stdc++.h>
using namespace std;

#define int long long 

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

int f[maxn][3],a[maxn],n,t[maxn];
char s[maxn];

void update(int &x,int y) {
    if(y>x) x=y;
}

signed main() {
    read(n);
    for(int i=1;i<=n;i++) {
        read(a[i]);
        if(i==n) break;
        scanf("%s",s+1);
        if(s[1]=='-') t[i+1]=-1;
        else t[i+1]=1;
    }t[1]=1;
    memset(f,-63,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++) {
        if(t[i]<0) {
            f[i][0]=f[i-1][0]-a[i];
            f[i][1]=max(f[i-1][0],f[i-1][1])-a[i];
            f[i][2]=max(f[i-1][1],f[i-1][2])+a[i];
        } else {
            f[i][0]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+a[i];
            f[i][1]=f[i-1][1]-a[i];
            f[i][2]=f[i-1][2]+a[i];
        }
    }
    write(max(max(f[n][0],f[n][1]),f[n][2]));
    return 0;
}
