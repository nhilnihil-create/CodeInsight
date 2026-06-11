#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int n;
	cin >> n;
	int arr[n] = {0};
	arr[0] = 0;
	int tmp, prev, diff=0;
	cin >> prev;
	REP(i, 1, n){
		cin >> tmp;
		if(tmp > prev) arr[i] = 1;
		else if(tmp < prev) arr[i] = -1;
		else arr[i] = 0;
		
		if(diff == 0) diff = arr[i];
		prev = tmp;
	}
	int ans = 0;
	REP(i, 1, n){
		if(diff == 0)diff=arr[i];
		else if(diff != arr[i] && arr[i] != 0){
			diff = arr[i+(i==n-1?0:1)];
			++ans;
		}
	}
	cout << ans+1;
	

}
