#include<bits/stdc++.h>
using namespace std;
int n,m;
void init(){
    cin>>n>>m;
}
void solve(){
    cout<<((!(n%3)||!(m%3)||!((m+n)%3))?"Possible":"Impossible")<<endl;
}
int main() {
    init();
    solve();
    return 0;
}
