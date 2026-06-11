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
#define pb push_back

const int maxn = 1e5+10;
const int inf = 1e9;
const lf eps = 1e-8;

int n;

vector<int > s,t;

signed main() {
    read(n);int p=101;n++;
    while(n>1) {if(n&1) t.pb(--p),n--;else s.pb(--p),n>>=1;}
    int m=s.size()+t.size();printf("%lld\n",m<<1);
    for(int i=0;i<(int)t.size();i++) printf("%lld ",t[i]);
    for(int i=s.size()-1;~i;i--) printf("%lld ",s[i]);
    for(int i=100-m+1;i<=100;i++) printf("%lld ",i);
    return 0;
}