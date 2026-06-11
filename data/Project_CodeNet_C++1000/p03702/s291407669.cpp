#include <bits/stdc++.h>
using namespace std;
int n,a,b,h[100001],cpy[100001];
int check(long long x) {
    for (int i=0; i<n; i++) cpy[i]=h[i];
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (cpy[i]>x*b) v.push_back(cpy[i]-x*b);
    }
    long long y=0;
    for (int i=0; i<v.size(); i++) y+=((v[i]+(a-b-1))/(a-b));
    if (y>x) return 0;
    else return 1;
}
int main() {
    cin>>n>>a>>b;
    for (int i=0; i<n; i++) cin>>h[i];
    int low=0,high=1e9;
    while (low!=high) {
        int med=(low+high)/2;
        int x=check(med);
        if (x) high=med;
        else low=med+1;
    }
    cout<<low<<'\n';
}