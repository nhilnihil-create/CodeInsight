#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;

int cnt[150];
char ch[200005];

int main() {
	scanf("%s", ch);
	string s = ch;
	for (int i=0 ; i<s.size() ; i++) cnt[s[i]]++;
	ll sol = 1;
	for (int i=0 ; i<s.size() ; i++) {
		sol += s.size()-i-cnt[s[i]];
		cnt[s[i]]--;
	}
	printf("%lld\n", sol);
	return 0;
}