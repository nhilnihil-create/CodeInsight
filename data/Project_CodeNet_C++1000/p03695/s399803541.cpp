#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main(){
	int n;
	cin >> n;
	int a[n];
	int sum=0;
	int col[9]={0,0,0,0,0,0,0,0,0};

	FOR(i,n){
		cin >>a[i];
		if(a[i] <400) col[0]++;
		else if(a[i] < 800) col[1]++;
		else if(a[i] <1200) col[2]++;
		else if(a[i] < 1600) col[3]++;
		else if(a[i] <2000) col[4]++;
		else if(a[i] <2400) col[5]++;
		else if(a[i] <2800) col[6]++;
		else if(a[i] <3200) col[7]++;
		else col[8]++;
	}
	FOR(i,8) if(col[i]>0)sum++;
	if(sum!=0)
	cout << sum <<" "<<sum+col[8] ;
	else 
	cout << 1 << " " << col[8];
	return 0;
}