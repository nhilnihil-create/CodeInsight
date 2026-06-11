#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    int num4=0;
    int num2=0;
    int num1=0;
    rep(i, n){
        if(v[i]%4==0) num4++;
        else if(v[i]%2==0) num2++;
        else num1++;
    }
    bool ok;
    if(num1>num4+1) ok=false;
    else if(num1==num4+1){
        if(num2==0) ok=true;
        else ok=false;
    }
    else  ok=true;
    if(ok) {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}