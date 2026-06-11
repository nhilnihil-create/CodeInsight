#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,ans=0; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) {
        if(a[a[i]-1] == i+1) ans++;
    }
    cout<<ans/2;
}