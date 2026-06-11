#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,l,t,a[N];
int main(){
    scanf("%d %d %d",&n,&l,&t);
    long long p=1;
    int x,w;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&w);
        if(w==1){
            a[i]=(x+t)%l;
            p=(p+(x+t)/l%n)%n;
        }
        else{
            a[i]=(x-t%l+l)%l;
            p=(p+n-(t+l-1-x)/l%n)%n;
        }
    }
    sort(a+1,a+n+1);
    if(p==0)p=n;
    for(int i=p;i<=n;i++)printf("%d\n",a[i]);
    for(int i=1;i<p;i++)printf("%d\n",a[i]);
}