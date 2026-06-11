//in the name of god
//if you read this code please search about imam hussain
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define endl "\n"
#define X first
#define Y second
#define pii pair<int,int>
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define read freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)

const int maxn=1e5+5;
const int mod=1e9+7;
const int inf=1e9;
const int del=728729;

ll poww(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));}
int n, ind;
int arr[maxn];
 
int main() {
	migmig;
	
	cin >> n;
 
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if (n == 1) {
		if (arr[0] % 2 == 1)
			return cout << "Second" , 0;
		else
			return cout << "First" , 0; 
	}
	
	sort(arr, arr + n , greater<int>());
	
	if (arr[0] == 1) {
		if (n % 2 == 1)
			return cout << "Second" , 0;
		else
			return cout << "First" , 0; 
			
		return 0;
	}
	
	ind = n;
	int h = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] >= i && arr[i] <= i) {
			ind = i;
			break;
		}
	}
	
	ind--;
 
	if ((arr[ind] - ind) % 2 == 0) {
		cout << "First";
		return 0;
	}
	
	int cnt = 0;
	int tmp = ind + 1;
	while (tmp < n && arr[tmp] == ind + 1) {
		tmp++;
		cnt++;
	}
	if (cnt % 2 == 1) {
		cout << "First";
		return 0;
	}
	cout << "Second";
	return 0;
}

