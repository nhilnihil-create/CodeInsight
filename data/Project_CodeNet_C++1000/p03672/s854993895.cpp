#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>
#define mod 1000000007
#define inf 1LL<<61
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	string a;
	cin >> a;
	int ans;
	for(int i = a.size() - 2; i >= 2; i -=2){
		ans = (i/2) * 2;
		for(int j = 0; j < i / 2; j++){
			if(a[j] != a[j + i / 2]){
				ans = 0;
			}
		}
		if(ans == (i/2) * 2){
			cout << ans;
			return 0;
		}
	}
	return 0;
}

