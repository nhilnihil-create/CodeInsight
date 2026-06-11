#include <iostream>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    long long a[n],b[n];
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    long long c[m],d[m];
    rep(i,m){
        cin>>c[i]>>d[i];
    }
    rep(i,n){
        long long tmp = 1010010000;
        int id =-1;
        for(int j=m-1;j>=0;j--){
            if (tmp>=abs(a[i]-c[j])+abs(b[i]-d[j])){
                id=j;tmp=abs(a[i]-c[j])+abs(b[i]-d[j]);
            }
        }
        cout<<id+1<<endl;
    }
    
    
}
