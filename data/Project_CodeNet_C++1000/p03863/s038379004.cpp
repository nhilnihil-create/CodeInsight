#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
string a;
int main(){
	int i, j;
	cin >> a;
	if(a[0] == a[a.length()-1] ^ a.length()%2==0){
		cout << "Second";
	}else {
		cout << "First";
	}
}
