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
	int w,h,n,a;
	cin >> w >> h >> n;
	int x[n],y[n],lx,mx,ly,my;
	tie(lx,mx,ly,my)=make_tuple(0,w,0,h);
	FOR(i,n){
		cin >> x[i];
		cin >> y[i];
		cin >> a;
		if(a==1) lx=max(lx,x[i]);
		if(a==2) mx=min(mx,x[i]);
		if(a==3) ly=max(ly,y[i]);
		if(a==4) my=min(my,y[i]);
	}
	//cout << lx <<"," << ly <<",- ," <<mx <<"," << my; 
	cout << max(0,(mx-lx))*max(0,(my-ly));

	return 0;
}