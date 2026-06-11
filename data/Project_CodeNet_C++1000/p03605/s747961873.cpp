#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    bool ok=false;
    if(n%10==9)ok=true;
    n/=10;
    if(n%10==9)ok=true;
    cout<<(ok==true?"Yes":"No")<<endl;
}
