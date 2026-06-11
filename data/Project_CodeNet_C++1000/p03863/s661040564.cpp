#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    int n = s.size();
    if((n % 2 == 0) ^ (s[0] == s[n-1])) cout << "Second" << endl;
    else cout << "First" << endl;
}