#include <bits/stdc++.h>
using namespace std;
int main(){
std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test;
    test=1;
    // cin>>test;
    while(test--)
    {
        long long i,j,n,m,q,a=0,t,b,c,temp,k,maxpeak=0,peak,d;
        string s;
        cin>>n;
        if(n<=6)
        {
            cout<<1;
            return 0;
        }
        else if(n<=11)
        {
            cout<<2;
            return 0;
            
        }
        a=n/11;
        b=n%11;
        if(b<=6 && b!=0)
        cout<<a*2+1;
        else if(b>6)cout<<a*2+2;
        else cout<<a*2;
        
    }
}