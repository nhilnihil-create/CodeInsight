#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
cin >> s;
rep(i,4)cout << s.at(i);
cout <<" ";
for(int i = 4; i < 12; i++)cout << s.at(i);
cout << endl;
}
