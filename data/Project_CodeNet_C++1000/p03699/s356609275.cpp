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
	set<int> s;
	int n;
	scanf("%d", &n);
	int arr[n];
	int j =0;
	rep(i,0,n){
		scanf(" %d", arr + i);
	}
	s.insert(0);
	rep(i,0,n){
		set<int> temp = s;
		for(auto el : temp){
			s.insert(el);
			s.insert(arr[i] + el);
		}

	}
	int max = 0;
	for(auto it = s.end(); it != s.begin();){
		it--;
		if(*it > max && *it % 10 != 0){
			max = *it;
		}
	}
	cout << max;
	return 0;
}

