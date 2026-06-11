#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    ll x,y;
    cin>>x>>y;
    cout<<(abs(x-y)<=1 ? "Brown" : "Alice")<<endl;
    return 0;
}