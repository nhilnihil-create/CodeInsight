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
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	string a;
	cin >> a;
	int arr[26];
	memset(arr, 0, sizeof(arr)); 
	REP(i,0,a.size()){
		arr[a[i] - 'a'] = arr[a[i] - 'a'] + 1;
		if(arr[a[i] - 'a'] > 1){
			cout << "no"; return 0;
		}
	}
	cout << "yes";

	
	return 0;
}

