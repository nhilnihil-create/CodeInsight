#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c; cin >> a >> b >> c;
    set<int> se;
    se.insert(a);
    se.insert(b);
    se.insert(c);
    cout << se.size() << endl;
}