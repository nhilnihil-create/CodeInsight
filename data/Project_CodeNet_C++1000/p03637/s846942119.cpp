#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, arr[nax], satu=0, dua=0, empat=0;	

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i]&1) satu++;
		else if(arr[i]%2==0){
			if(arr[i]%4==0) empat++;
			else dua++;
		}
	}
	if(dua==0){
		if(satu<=empat+1){
			cout << "Yes" << '\n';
		}
		else{
			cout << "No" << '\n';
 		}
	}
	else{
		if(satu<=empat){
			cout << "Yes" << '\n';
		}
		else{
			cout << "No" << '\n';
		}
	}
}
