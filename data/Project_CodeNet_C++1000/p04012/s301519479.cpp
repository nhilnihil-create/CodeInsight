#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }

main()
{
    //fastio;
    string s;
    map<char, int>mp;
    cin>>s;
    for(int i=0; i<s.size(); i++) mp[s[i]]++;
    for(char i='a'; i<='z'; i++) {
        if(mp[i]%2) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
