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

int main(){
	int n,t;
	cin >> n >> t;
	int arr[n];
	int k=0;
	while(cin >> arr[k++])
		;
	int sum =0;
	REP(i,1,n){
		if(arr[i] - arr[i-1] > t)
			sum += t;
		else
			sum += arr[i] - arr[i-1];
	}
	cout << sum + t;
	return 0;
}

