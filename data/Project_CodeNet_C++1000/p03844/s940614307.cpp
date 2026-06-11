#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
const char newline = '\n';

int main()
{
	int a = 0, b = 0, k = 0;
	ll l = 0;
	char oper;
	cin >> a >> oper >> b;
  	switch(oper)
    {
      case '+':
        l= a+b;
        break;
      case '-':
        l = a-b;
        break;
    }
	cout << l << newline;
}