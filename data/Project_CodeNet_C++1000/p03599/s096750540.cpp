#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	
	int a_water = a*100;
	int a_sugar = 0;
	int water,sugar;
	for(int at=0; at*a*100<=f; at++){
		for(int bt=0; (at*a+bt*b)*100<=f; bt++){
			if(at+bt==0) continue;
			for(int ct=0; (at*a+bt*b)*100+ct*c<=f; ct++){
				for(int dt=0; (at*a+bt*b)*100+ct*c+dt*d<=f; dt++){
					water = (at*a+bt*b)*100;
					sugar = ct*c+dt*d;
					if(sugar > e*water/100) break;
					if(a_sugar*(water+sugar) < sugar*(a_water+a_sugar)){
						a_sugar = sugar;
						a_water = water;
					}
				}
			}
		}
	}
	
	cout << a_water+a_sugar<< " "<< a_sugar<<endl;
	
	return 0;
}