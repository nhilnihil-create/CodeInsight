#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    set<char> a;
    for (int i = 0; i < S.length(); i++)
    {
        a.insert(S[i]);
    }
    if (a.size() == S.length())
    {
        cout << "yes" << endl;
    } else
    {
        cout << "no" << endl;
    }
    
    
    
  return 0;
}