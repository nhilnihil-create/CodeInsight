#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll p = 1000000007;
int main(){
    ll n, m, A = 0, B = 0, lst, a = 0, b = 0;
    cin>>n>>m;
    cin>>lst;
    for(int i=1;i<n;i++){
        ll tmp;
        cin>>tmp;
        a = (a + (i*(tmp - lst)%p))%p;
        A = (A + a)%p;
        lst = tmp;
    }
    cin>>lst;
    for(int i=1;i<m;i++){
        ll tmp;
        cin>>tmp;
        b = (b + (i*(tmp-lst)%p))%p;
        B = (B + b)%p;
        lst = tmp;
    }
    cout<<A*B%p<<endl;
    return 0;
}