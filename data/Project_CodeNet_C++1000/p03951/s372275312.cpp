#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    string s, t;
    cin>>s>>t;

    int ans = 0;

    for (int i=0; i<=n; i++)
        if (string(s.begin()+n-i, s.end()) == string(t.begin(), t.begin()+i))
            ans = i;

    cout<<2*n-ans<<endl;
}
