#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int H, W;
string S[100];

int cnt[26] ={};

signed main(){
	cin >> H >> W;
	rep(i, H) cin >> S[i];

	rep(i, H){
		rep(j, W){
			cnt[S[i][j]-'a']++;
		}
	}
	if(H%2 == 0 && W%2 == 0){
		rep(i, 26){
			if(cnt[i]%4 != 0){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	}
	if(H%2 == 1 && W%2 == 0){
		int two = 0;
		rep(i, 26){
			if(cnt[i]%4 == 2){
				two++;
			}
			if(cnt[i]%2 != 0){
				cout << "No" << endl;
				return 0;
			}
		}
		if(two <= W/2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	if(H%2 == 0 && W%2 == 1){
		int two = 0;
		rep(i, 26){
			if(cnt[i]%4 == 2){
				two++;
			}
			if(cnt[i]%2 != 0){
				cout << "No" << endl;
				return 0;
			}
		}
		if(two <= H/2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	if(H%2 == 1 && W%2 == 1){
		int one = 0;
		int two = 0;
		rep(i, 26){
			if(cnt[i]%4 == 2){
				two++;
			}
			if(cnt[i]%4 == 1){
				one++;
			}
			if(cnt[i]%4 == 3){
				one++;
				two++;
			}
		}
		if(one <= 1 && two <= H/2 + W/2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}