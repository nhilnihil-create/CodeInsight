#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;

    cin >> n;
    int c,a1,a2,a[n],suma=0,maxa=-1*1e10;
    cin >>c;
    a1=c;
    suma+=a1;
    for(int i=1;i<n;i++){
        cin >> a2;
        a[i-1]=a2-a1;
        maxa =max(maxa,a[i-1]);
        a1=a2;
        suma+=a1;
    }
    a[n-1]=c-a1;
    maxa=max(maxa,a[n-1]);
    //cerr << maxa<<endl;
    int sum1=0,t=0;
    for(int i=0;i<n;i++){
        sum1+=(maxa-a[i])/n;
       // cerr << sum1<<endl;
        if((maxa-a[i])%n!=0){
            t=1;
            break;
        }
    }
    if(t==1||maxa!=sum1)cout <<"NO";
    else{
        int y= 2*suma- maxa*n*(n+1);
        if(y<0||y%(n*n*(n+1))!=0)cout <<"NO";
        else cout <<"YES";


    }
    return 0;
}