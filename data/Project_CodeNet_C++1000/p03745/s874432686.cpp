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
	int n, ans=0;
	cin >> n;
	int arr[n];
	REP(i, 0, n) cin >> arr[i];
	REP(i, 0, n){
		while(i < n-1 && arr[i] == arr[i+1]) ++i;
		
		if(i < n-1  && arr[i] > arr[i+1]) while(i < n-1 && arr[i] >= arr[i+1]) ++i;
		else if(i < n-1 && arr[i] < arr[i+1]) while(i < n-1 && arr[i] <= arr[i+1]) ++i;
		++ans;
	}
	cout << ans;

}
