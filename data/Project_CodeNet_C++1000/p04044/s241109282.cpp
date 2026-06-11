#include<bits/stdc++.h>

using namespace std;

long long n,q,m,k,t,l;

int main(){
    cin>>n>>m;
    vector<string>v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++){
        cout<<v[i];
    }
}
