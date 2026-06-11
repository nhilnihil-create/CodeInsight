#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n,L,T,x[N],w[N];
int main() {
    scanf("%d%d%d",&n,&L,&T);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&w[i]);
    int mk=0;
    for(int i=1;i<=n;i++) {
        if(w[i]==1) {
            mk+=(x[i]+T)/L;
            mk%=n;
            x[i-1]=(x[i]+T)%L;
        }
        else{
            mk-=(L-x[i]-1+T)/L;
            mk%=n;
            x[i-1]=((x[i]-T)%L+L)%L;
        }
    }
    sort(x,x+n);
    for(int i=0;i<n;i++) {
        // cout<<(i+mk+n)%n<<endl;
        printf("%d\n",x[(i+mk+n)%n]);
    }
    
}