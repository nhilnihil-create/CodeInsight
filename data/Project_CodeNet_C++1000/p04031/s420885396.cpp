#include <bits/stdc++.h>
using namespace std;
int c(int d,vector<int> v){
    int e = 0;
    int n = v.size();
    for (int y=0;y<n;y++){
        e =(v[y]-d)*(v[y]-d) + e;
    }
    return e;
}
int main() {
    int a=0;
    int n; cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    for (int u=0;u<n;u++){
        a = v[u]+a;
    }
    int b = a/n;
    cout << min(c(b,v),c(b+1,v));
}