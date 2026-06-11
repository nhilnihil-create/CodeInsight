#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
    
int main(){
    string s;
    cin >> s;
    int n = s.size() - 2;
    cout << s.at(0) << n << s.at(n+1) << endl;
    return 0;
}