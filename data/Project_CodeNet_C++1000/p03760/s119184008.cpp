#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    string a, b; cin>>a>>b;

    char str[MAX];
    for (int i=0, j=0; i<max(a.size(), b.size()); i++, j+=2){
        if(i<a.size()) cout<<a[i];
        if(i<b.size()) cout<<b[i];
    }
}

int main(){
    solve();
    Bye;
}