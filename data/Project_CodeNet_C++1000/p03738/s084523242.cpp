#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll MAX = 1e2;

void solve(){
    string a, b; cin>>a>>b;
    if(a == b) printf("EQUAL");
    else if(a.size() > b.size() || (a[0]-'0') > (b[0]-'0') &&
       a.size() == b.size())
        printf("GREATER");
    else printf("LESS");
}

int main(){
    solve();
    Bye;
}