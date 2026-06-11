#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll n, L;
ll a[100000];

int main() {
	cin >> n >> L;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	if(a[0] + a[1] >= L){
		cout << "Possible" << endl;
		for(int i = n - 1; i >= 1; i--)cout << i << endl;
		return 0;
	}
	if(a[n - 1] + a[n - 2] >= L){
		cout << "Possible" << endl;
		for(int i = 1; i < n; i++)cout << i << endl;
		return 0;
	}
	
	for(int i = 0; i < n - 1; i++){
		if(a[i] >= L){
			cout << "Possible" << endl;
			for(int j = 1; j <= i; j++)cout << j << endl;
			for(int j = n - 1; j > i; j--)cout << j << endl;
			return 0;
		}
		if(a[i] + a[i + 1] >= L){
			cout << "Possible" << endl;
			for(int j = 1; j <= i; j++)cout << j << endl;
			for(int j = n - 1; j > i + 1; j--)cout << j << endl;
			cout << i + 1 << endl;
			return 0;
		}
	}
	
	cout << "Impossible" << endl;
	return 0;
}
