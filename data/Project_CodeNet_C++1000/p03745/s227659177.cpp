#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,ans=1; cin>>n;
    bool inc = false, dec = false;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n-1; i++) {
        if(a[i] < a[i+1]) inc = true;
        else if(a[i] > a[i+1]) dec = true;
        if(inc && dec) {
            ans++;
            inc = false;
            dec = false;
        }
    }
    printf("%d", ans);
}