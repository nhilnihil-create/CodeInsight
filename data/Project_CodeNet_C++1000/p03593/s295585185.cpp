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
/*a b c b 
  a d d a 
  a d d a
  a b c b 
  	*/
/*
	a b e b a
	c d f d c
	a b e b a
*/
/*
	a b a
	x y x
	x y x
	a b a
*/

int main(){
	int h,w;
	char c;
	int alp[26];
	FOR(i,26) alp[i]=0;
	cin >> h >> w;
	FOR(i,h)
		FOR(j,w){
			cin >> c;

			alp[c-'a']++;
		}
	int c1=0,c2=0,c4=0;
	if(h%2==0 && w%2==0) {
		c4=h*w/4;
	}
	else if(h%2==1 && w%2==1){
		c1=1;
		c2=h/2+w/2;
		c4=(h*w-c1-c2*2)/4;
	}
	else if(w%2==1){
			c2=h/2;
			c4=(h*w-h)/4;	
		}
	else{
		c2=w/2;
		c4=(h*w-w)/4;
	}
	
	//error(c1,c2,c4);
	FOR(i,26) 
		{	
			int x=c4;
			c4-=min(alp[i]/4,c4);
			alp[i]-=min((alp[i]/4)*4,x*4);
			//error(alp[i],c4);
		}
	if(c4 > 0) cout << "No";
	else{
		FOR(i,26){
			int x=c2;
			c2-=min(alp[i]/2,c2);
			alp[i]-=min((alp[i]/2)*2,x*2);
		}
		if(c2>0) cout << "No";
		else{
			FOR(i,26){
				int x=c1;
				c1-=min(alp[i],c1);
				alp[i]-=min(alp[i],x);
			}
			if(c1 > 0) cout << "No";
			else cout << "Yes";
		}
	} 

	

	return 0;
}
/* a b b a
   a d d a
   a b b a*/