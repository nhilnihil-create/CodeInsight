#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

vector<int> strcompress(string S, int N){
    int count = 1;
    char c = S[0];
    vector<int> vec; 
	rep(i, N-1){
		if(c == S[i+1]){
			count++;
		}else{
			vec.push_back(count);
			count = 1;
			c = S[i+1];
		}
	}
	vec.push_back(count);
    return vec;
}

vector<int> domino_type;
int main() {
    cin >> N;
    string s;
    cin >> s;
    cin >> s;
    domino_type = strcompress(s, N);
    ll sum = (domino_type[0] == 1 ? 3 : 6);
    rep(i, domino_type.size() - 1){
        ll mul;
        if(domino_type[i] == 1 && domino_type[i+1] == 1){
            mul = 2;
        }else if(domino_type[i] == 1 && domino_type[i+1] == 2){
            mul = 2;
        }else if(domino_type[i] == 2 && domino_type[i+1] == 1){
            mul = 1;
        }else if(domino_type[i] == 2 && domino_type[i+1] == 2){
            mul = 3;
        }
        sum = (sum * mul)%MOD;
    }
    cout << sum;
}
