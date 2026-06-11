#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
string s;
string res;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>s;
    int acc=0;
    for (char c: s) {
	if (c=='(') acc++;
	if (c==')') acc--;
	if (acc<0) {
	    res+='(';acc=0;
	}
    }

    res += s;
    while (acc--) res+=')';
    out(res);
  

    return 0;
}
