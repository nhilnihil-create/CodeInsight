#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int k;
    cin>>k;

    for (char &c: s) {
        if (c == 'a')   continue;
        int need = 'z'-c+1;
        if (need <= k)    k-=need, c='a';
    }

    s.back() = 'a' + (s.back()-'a'+k)%26;

    cout<<s<<endl;
}
