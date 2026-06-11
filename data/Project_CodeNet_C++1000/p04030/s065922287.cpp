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

    deque<char> v;

    for (int i=0;i<s.size();++i){
        if (s[i]== '0') {
                v.push_back('0');}
        else if (s[i]== '1') {
                v.push_back('1');}
        else if (s[i]== 'B'){
            if (!v.empty()) v.pop_back();
        }
    }

    for (auto i=v.begin();i!=v.end();++i){
        cout << *i;
    }

    return 0;
}
