#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

inline int read(){
    char ch=getchar();int x=0,f=1;
    while(ch>'9' || ch<'0'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int n,a[20000015];

int small(int i,int j,int k) {
    return a[i]<=k && a[j]<=k;
}

int big(int i,int j,int k){
    return a[i]>k && a[j]>k;
} 

int check(int k){
    for(int i=0;i<n-1;i++){
        if(big(n+i,n+i+1,k) || big(n-i,n-i-1,k)) return 0;
        if(small(n+i,n+i+1,k) || small(n-i,n-i-1,k)) return 1;
    }
    return small(1,1,k);
}

int main(){
    n=read();
    for(int i=1;i<=2*n-1;i++){
        a[i]=read();
    }
    int l=1,r=2*n-1,ans;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) {
            r=mid;
        }
        else l=mid+1;
    }
    cout<<r;
    return 0; 
}