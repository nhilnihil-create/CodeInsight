#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int a,b;
    char op;
    cin>>a>>op>>b;

    if(op=='+') cout<<a+b<<"\n";
    else cout<<a-b<<"\n";
    return 0;
}