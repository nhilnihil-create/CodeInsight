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
	int size;
	cin >> size;
	int arr[size];
	rep(i,0,size)
		cin >> arr[i];
	char mark[8];
	memset(mark,0,sizeof(mark));
	int count = 0;
	rep(i,0,size){
		if(arr[i]/400 <=  7)
			mark[arr[i]/400] = 1;
		else
			count++;

	}
	int cnt = 0;
	rep(i,0,8)
		if(mark[i])
			cnt++;
	if(cnt == 0)
		cout << 1 << " " << cnt + count;
	else
		cout << cnt << " " << cnt + count;
	return 0;
}

