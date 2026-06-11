#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,l;
    cin >> n >> l;
    string a;
    multiset<string> s;
    while(n--){
        cin >> a;
        s.insert(a);
    }
    for(auto i=s.begin();i!=s.end();++i){
        cout << *i;
    }
    return 0;
}
