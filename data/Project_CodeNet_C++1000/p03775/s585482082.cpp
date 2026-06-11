#include <bits/stdc++.h>
using namespace std;
int digitcnt(long long a){
    int cnt=0;
    while(a>0){
        a/=10;
        cnt++;
    }
    return cnt;
}
int main(){
    long long n, i, b, ans=10000000;
    cin >> n;
    for(i=1;i<=sqrt(n);i++){
        long long f, digcnta, digcntb;
        if(n%i==0){
            b=n/i;
            digcnta=digitcnt(i);
            digcntb=digitcnt(b);
            f=max(digcnta, digcntb);
            ans=min(ans, f);
        }
    }
    cout << ans <<endl;
    return 0;
}