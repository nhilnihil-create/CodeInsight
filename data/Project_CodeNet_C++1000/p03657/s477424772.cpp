#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int a,b;
    cin>>a>>b;
    bool ok=false;
    if(a%3==0)ok=true;
    if(b%3==0)ok=true;
    if((a+b)%3==0)ok=true;
    cout<<(ok==true?"Possible":"Impossible")<<endl;
}
