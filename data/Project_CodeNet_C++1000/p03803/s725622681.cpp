#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long

void solve(){
    int a, b; cin>>a>>b;

    a = a == 1 ? 14 : a;
    b = b == 1 ? 14 : b;

    if(a == b)
        cout<<"Draw"<<endl;
    else
        cout<<((a>b)?"Alice" : "Bob")<<endl;
}

int main(){
    solve();
    Bye;
}