#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+10
int n,a[MAXN];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
bool f(){
    long long sum=0;
    bool flag=0;
    int num=0;
    for(int i=1;i<=n;i++){
        sum+=a[i]-1;
        if(a[i]&1)num++;
        if(a[i]==1)flag=1;
    }
    if(flag)return sum%2;
    if((n-num)%2)return 1;
    if(num==1){
        int g=0;
        for(int i=1;i<=n;i++)
            if(a[i]&1)a[i]--;
        for(int i=1;i<=n;i++)g=gcd(g,a[i]);
        for(int i=1;i<=n;i++)a[i]/=g;
        return f()^1;
    }
    return 0;

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(f())printf("First");
    else printf("Second");
}