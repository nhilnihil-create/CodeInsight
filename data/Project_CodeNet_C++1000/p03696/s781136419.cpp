#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;


int main() {
	int N;
	string S;
	cin >> N >> S;
	int sum = 0;
	int countl = 0;
	rep(i, N) {
		if (S[i] == '(') sum++;
		else sum--;
		if (sum < 0) {
			countl++;
			sum++;
		}
	}
	if(sum>0){
		rep(i, sum) S = S + ")";
	}
	if (countl > 0) {
		rep(i, countl) S = "(" + S;
	}
	cout << S << endl;
}