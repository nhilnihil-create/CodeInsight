#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;
 
 
int main() {
    int a,b,c;
    cin >> a>>b>>c;
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout<< s.size() <<endl;

}