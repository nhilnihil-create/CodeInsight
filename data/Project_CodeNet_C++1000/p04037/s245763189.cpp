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

const int maxn = 1e5+10;
const int inf = 1e9;
const lf eps = 1e-8;

int n,a[maxn],ans;

int main() {
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1),reverse(a+1,a+n+1);a[0]=a[1];
    for(int i=0;i<=n;i++)
        if(a[i+1]<=i) {
            ans=(a[i]-i)&1;
            int j=i+1;while(a[j]==i&&j<=n) j++;
            ans|=(j-i+1)&1;break;
        }puts(ans?"First":"Second");
    return 0;
}
