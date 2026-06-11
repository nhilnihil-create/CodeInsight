#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define bye return 0
#define Yes cout << "Yes" << "\n"
#define No  cout << "No" << "\n"
#define YES cout << "YES" << "\n"
#define NO cout << "NO" << "\n"
#define endl cout << "\n"
typedef long long ll;
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    map<int, int> m;
    set<int> s;
    int a, b, c;
    cin >> a >> b >> c;
    s.insert(a); 
    s.insert(b);
    s.insert(c);
    cout << s.size() << "\n";
    bye;
}