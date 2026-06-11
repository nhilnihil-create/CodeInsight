#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin >> a;
    set<char>s (all(a));
    (s.size() == a.size()) ? cout << "yes" : cout << "no"; 
    return 0;
}