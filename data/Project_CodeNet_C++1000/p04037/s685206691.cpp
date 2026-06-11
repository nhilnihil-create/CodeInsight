#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define ld long double
#define re register
#define li inline
const int INF=0x7ffffff;
const int N=100010;
li ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[N];
bool cmp(ll x,ll y){
    return x>y;
}
int  main(){
    // freopen("1009.in", "r", stdin);
	// freopen("1009.out", "w", stdout);
    n=read();ll p1,p2;
        for(int i=1;i<=n;i++) a[i]=read();
        sort(a+1,a+1+n,cmp);
        for(int i=0;i<=n;i++){
            if(i>=a[i+1]){
                p1=i;
                break;
            }
        }
        for(int i=1;i<=n+1;i++){
            if(a[i]<=p1-1){
                 p2=i-1;
                 break;
            }
        }
        if(((p2-p1)%2)||((a[p1]-p1)%2))  printf("First\n");
        else printf("Second\n");

    // fclose(stdin);
	// fclose(stdout);
    return 0;
}
/*
3
3 2 1
*/
