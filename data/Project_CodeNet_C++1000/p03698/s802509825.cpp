#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;



int main() {
    set<char> a;
    string s;
    cin >> s ;
    for(char x: s)
    {
        a.insert(x);
    }
    if (size(s) == size(a))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}
