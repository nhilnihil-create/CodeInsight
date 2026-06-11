#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
set<ll> a;

int main(){
	cin >> n;

	for(ll i=0, temp; i<n; i++){
		cin >> temp;
		if(a.count(temp)){
			a.erase(temp);
		}
		else{
			a.insert(temp);
		}
	}

	cout << a.size() << endl;
}
