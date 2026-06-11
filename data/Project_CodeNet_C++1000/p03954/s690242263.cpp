#include<bits/stdc++.h>
using namespace std;

const int N =2e5+10;
int n,a[N];
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline bool check(const int &k)
{
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))return 1;
    if((a[n-1]> k&&a[n]> k)||(a[n]> k&&a[n+1]> k))return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))return 1;
        if((a[n+i]> k&&a[n+i+1]> k)||(a[n-i]> k&&a[n-i-1]> k))return 0;
    }
    return a[1]<=k;
}

int main(){
    n=read();
    for(int i=1;i<n<<1;i++)a[i]=read();
    int l=1,r=(n<<1)-1;
    while(l<r){
        int mid=l+r>>1;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d",l);
}
