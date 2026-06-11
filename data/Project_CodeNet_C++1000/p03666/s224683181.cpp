#include<bits/stdc++.h>
using namespace std;
int main(){
    long n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    
    if(a>b)swap(a,b);
    
    bool chk = false;
    for(long i=0;i<=n-1;i++){
        long minn = c*i - d*(n-1-i);
        long maxx = d*i - c*(n-1-i);
        if(a+minn <= b && b <= a+maxx)chk=true;
    }
    if(chk)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}