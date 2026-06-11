#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;

ll const MAX = 200005;
string s;
ll ans_length = 1;
ll section[MAX];
ll str[MAX];
char ans[MAX];
ll alph[30];
ll const a_size = 26;

void alph_init() {
	REP(i, 1, a_size) {
		alph[i] = 0;
	}
}
bool alph_check() {
	REP(i, 1, a_size) {
		if (alph[i] == 0) {
			return false;
		}
	}
	return true;
}

void f(ll t, ll v, ll ans_length) {
	//section[v]からv+1文字目を選ぶ
	alph_init();
	REP(i, t + 1, section[v+1] - 1) {
		alph[str[i]]++;
	}
	REP(i, 1, a_size) {
		if (alph[i] == 0) {
			ans[v + 1] = i;
			break;
		}
	}
	if (v + 1 < ans_length) {
		ll tt = section[v+1];
		while (str[tt] != ans[v + 1]) {
			tt++;
		}
		f(tt, v + 1, ans_length);
	}
}

int main() {
	cin >> s;
	ll n = s.size();
	REP(i, 0, s.size() - 1) {
		str[i + 1] = s[i] - 'a' + 1;
	}
	alph_init();
	for (ll i = n; i >= 1; i--) {
		ll cur = str[i];
		alph[cur]++;
		if (alph_check()) {
			section[ans_length] = i;
			alph_init();
			ans_length++;
		}
	}
	REP(i, 1, a_size) {
		if (alph[i] == 0) {
			ans[1] = i;
			break;
		}
	}
	if (ans_length > 1) {
		reverse(section + 1, section + ans_length);
		section[ans_length] = n + 1;
		alph_init();
		ll tt = section[1];
		while (str[tt] != ans[1]) {
			tt++;
		}
		REP(i, tt + 1, section[2] - 1) {
			alph[str[i]]++;
		}
		REP(i, 1, a_size) {
			if (alph[i] == 0) {
				ans[2] = i;
				break;
			}
		}
		if (ans_length > 2) {
			tt = section[2];
			while (str[tt] != ans[2]) {
				tt++;
			}
			f(tt, 2, ans_length);
		}

	}
	REP(i, 1, ans_length) {
		cout << char((ans[i] - 1) + 'a');
	}
	cout << endl;
}