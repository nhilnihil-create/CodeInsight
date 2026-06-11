#include <bits/stdc++.h>

using namespace std;

int main() {
    int n ; cin>>n;
    vector<int>v(n + 1);
    for(int i = 1;  i <= n; ++i){
        int x; cin>>x;
        v[i] = x;
    }
    int cnt = 0;
    for(int i = 1 ; i <= n; ++i){
        if(i == v[v[i]])cnt++;
    }
    cout<<(cnt >> 1)<<"\n";
}