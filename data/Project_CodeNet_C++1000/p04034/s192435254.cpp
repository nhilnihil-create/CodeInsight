#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define reall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

int main(){

	int N, M;
	cin >> N >> M;
	vector<pair<int, bool>> V(N, mpair(1, false));
	V[0].second = true;
	int x, y;
	for(int i = 0; i < M; i++){
		cin >> x >> y;
		x--;
		y--;
		if(V[x].second){
			V[y].second = true;
		}
		V[x].first--;
		V[y].first++;
		if(V[x].first == 0){
			V[x].second = false;
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(V[i].second)ans++;
	}
	cout << ans << endl;

	return 0;
}
