#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int cost = min(n,k)*x + (n-k > 0 ? (n-k)*y : 0);
    cout<<cost<<endl;
    return 0;
}