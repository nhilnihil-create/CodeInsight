#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define ll long long 
//#define int long long
#define ld long double
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define iii pair<int,ii>
#define il pair<int,ll>
#define pll pair<ll,ll>
#define _path pair<ll,pair<ll,int> > // length, numlength, node,we also take numlength to be negetive so that paths with the same length is sorted by descending order of number of such path. this is essential otherwise it will lead to undercounting of number of same length paths
#define vv vector
//#define endl '\n'
using namespace std;

const int MAXN = 100*1000 + 5;
const ll INF = 1e17;
const ll MOD = 1e9 +7;


ll startTerm[MAXN];
ll diffTerm[MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;
	int arr[n];
	FOR(i,n)cin >> arr[i];FOR(i,n)arr[i]--;
	// 0,1,2,3,4,5,6,7
	ll sum = 0;
	FOR(i,n){
		if(i == 0)continue;
		if(arr[i] == arr[i-1])continue;
		if(arr[i] > arr[i-1]){
			sum += arr[i] - arr[i-1];

			startTerm[arr[i-1]+1] += 0;
			diffTerm[arr[i-1]+1] += 1;

			startTerm[arr[i] + 1] += -(arr[i]-arr[i-1]);
			diffTerm[arr[i] + 1] += -1;
		}else{
			startTerm[arr[i-1]+1] += 0;
			diffTerm[arr[i-1]+1] += 1;

			startTerm[0] += m - arr[i-1] - 1;
			diffTerm[0] += 1;

			int totDist = arr[i] + m-arr[i-1];
			sum += totDist;

			startTerm[arr[i] + 1] += -totDist;
			diffTerm[arr[i] + 1] += -1;
		}
	}
	FOR(i,m){
	//	cout << startTerm[i] << " ";
	}
	//cout << endl;
	//FOR(i,m)cout << diffTerm[i] << " ";cout << endl;
	ll a = 0;
	ll d = 0;
	ll mxval = 0;
	
	ll term = 0;
	FOR(i,m){
		term += startTerm[i];
		term += d;
		//cout << term << " " << endl;
		mxval = max(mxval,term);
		d += diffTerm[i];
		
	}	
	//cout << sum << endl;
	cout << sum - mxval << endl;

	return 0;
}