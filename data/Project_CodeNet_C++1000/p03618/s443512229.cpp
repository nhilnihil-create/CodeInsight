#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    long long ans = n*(n+1LL)/2+1;
    for(char c='a'; c<='z'; c++){
        int cnt = count(s.begin() ,s.end() ,c);
        ans -= cnt*(cnt+1LL)/2;
    }
    cout << ans << endl;
}
