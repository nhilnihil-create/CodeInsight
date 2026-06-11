#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 4e5 + 5;
const int Mod = 1e9 + 7;
int lst[Max];

int main()
{
	ll n;
	cin >> n;
	ll res = n / 11 * 2;
	if (n % 11 != 0 && n % 11 <= 6)res++;
	else if (n % 11 != 0 && n % 11 > 6)res += 2;
	cout << res;
}