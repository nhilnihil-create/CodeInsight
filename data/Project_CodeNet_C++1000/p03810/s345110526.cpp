#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
void sub(int x){if(x)puts("First");else puts("Second");exit(0);}
int gcd(int a,int b){
    if(!a||!b)return a+b;
    return gcd(b,a%b);
}
int n,a[N];
bool check(){
    int ji=0;
    int dj=0;
    int ans=0;
    rep(i,1,n){
        ans^=(!(a[i]&1));
        if(a[i]&1){++ji;dj=i;}
    }
    if((ji!=1)||(a[dj]==1))return ans;
    if(ans)return ans;
    a[dj]--;
    int c=0;
    rep(i,1,n)c=gcd(c,a[i]);
    rep(i,1,n)a[i]/=c;
    return !check();
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    if(n==1)sub(n%2==0);
    sub(check());
    return 0;
};



