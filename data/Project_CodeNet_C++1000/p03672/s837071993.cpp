#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n=s.size();


    while(s.size()>0){
        s = s.substr(0,s.size()-2);
        string s1 = s.substr(0,s.size()/2);
        string s2 = s.substr(s.size()/2);
        if (s1 == s2){
            cout << s.size();
            return 0;
        }
    }

    return 0;
}
