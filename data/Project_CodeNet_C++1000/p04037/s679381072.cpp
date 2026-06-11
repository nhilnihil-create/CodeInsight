#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,a[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi();
    sort(a+1,a+n+1,greater<int>());
    int ans=0;
    for(int i=0;i<=n;i++)
        if(a[i+1]<=i) {
            ans=(a[i]-i)&1;
            int j=i+1;
            while(a[j]==i) j++;
            ans|=(j-i+1)&1;
            break;
        }
    puts(ans?"First":"Second");
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
