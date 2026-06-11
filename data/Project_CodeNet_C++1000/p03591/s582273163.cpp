#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    string s;
    cin >> s;
    if (s.size() >= 4 && s.substr(0,4) == "YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}