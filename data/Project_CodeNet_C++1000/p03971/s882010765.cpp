#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N,A,B;
	string S;
	cin >> N >> A >> B >> S;
	int count = 0, countb = 0;
	rep(i, N) {
		if(S[i] == 'c') {
			cout << "No" << endl;
			continue;
		}
		else if(S[i] == 'a') {
			if(count < A+B) {
				cout << "Yes" << endl;
				count++;
				continue;
			}
			cout << "No" << endl;
		}
		else if(S[i] == 'b') {
			if(count < A+B && countb < B) {
				cout << "Yes" << endl;
				count++;
				countb++;
				continue;
			}
			else cout << "No" << endl;
		}
	}

  return 0;
}
