#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

const int AMAX = 100000;
ll arr[AMAX + 1];

int main(){
	int N;
	ll K;
	cin >> N >> K;

	REP(i,0,N){
		int x,y;
		cin >> x >> y;
		arr[x] += y;
	}
	for(int i = 0; i <= AMAX; i++){
		if(K <= arr[i]){
			cout << i;
			break;
		}
		K -= arr[i];
	}
	return 0;
}

