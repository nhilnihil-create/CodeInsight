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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> m;
    vector<int> v;
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(), v.end());

    if((v[0]+v[1])==v[2]) Yes;
    else No;

    // for(auto i: v) cout << i;
    // 	endl;
    bye;
}