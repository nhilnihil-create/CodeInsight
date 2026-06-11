#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
ll a,b;
cin >> a >>b;
ll n = b-a+1;
if(a==0||b==0||(a<0&&b>0))cout <<"Zero" << endl;
else if(n%2==0||(n%2!=0&&a>0)) cout <<"Positive" << endl;
else cout << "Negative" << endl;
}
