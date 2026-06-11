#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n;
    cin >> n;
    map<int, int> m;

    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        m[x]++;
    }

    int ans=0;
    for(auto x:m){
        if(x.second&1)
            ans++;
    }
    cout << ans;
}
