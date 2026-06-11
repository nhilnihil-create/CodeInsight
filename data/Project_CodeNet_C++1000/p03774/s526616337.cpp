#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    long long a[n],b[n],c[m],d[m];
    f(i,0,n){
        cin>>a[i]>>b[i];
    }
    f(i,0,m){
        cin>>c[i]>>d[i];
    }
    f(i,0,n){
        long long ans=400000000,ansi=0;
        f(j,0,m){
            if(ans>abs(a[i]-c[j])+abs(b[i]-d[j])){
                ans=abs(a[i]-c[j])+abs(b[i]-d[j]);
                ansi=j;
            }
        }
        cout<<ansi+1<<endl;
    }
    return 0;
}
