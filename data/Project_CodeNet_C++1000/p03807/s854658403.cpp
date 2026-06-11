#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int o=0, e=0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a&1)e++;
        
    }
    if(e%2==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

