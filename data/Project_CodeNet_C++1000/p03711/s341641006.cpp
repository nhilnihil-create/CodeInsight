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
	int arr[13];
	memset(arr, 0, sizeof(arr));
	arr[1] = arr[3] = arr[5] = arr[7] = arr[10] = arr[8] = arr[12] = 1; 
	arr[4] = arr[6] = arr[9] = arr[11] = 2;
	arr[2] = 3;
	int x,y;
	cin >> x >> y;
	string out = (arr[x] == arr[y]) ? "Yes" : "No";
	cout << out;
	return 0;
}

