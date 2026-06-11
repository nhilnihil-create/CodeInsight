#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 200005 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
 
int v ; 
vector<PII> a(9) ; 
VI tmp(10) ; 

bool fun(const PII &a, const PII &b) {
	if(a.first == b.first) {
		return a.second > b.second ; 
	}

	return a.first < b.first ; 
}

void solve() {
	int n ; 
	cin >> n ; 

	string s ; 
	cin >> s ;
	int cur = 0 ,c1=0,c2=0,d=0;
	VI a(n)  ; 
	FOR(i,0,n) {
		if(s[i] == '('){
			bool ok = false ;
			FOR(j,0,-cur) {
				cout << '(' ;
				c1++; 
				ok = true ; 
			}
			if(ok)
				cur = 0 ; 
			c1++;
			cur++;
			
		}
		if(s[i]==')') {
			c2++; 
			cur--;
			if(cur > 0)
				++d ; 
		}
	}  
	FOR(i,0,-cur)
	cout << '(' ; 
	cout << s ; 
	FOR(i,0,c1-c2)
	cout << ')' ; 
	
	
	
 

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	int  t =1; 
	//cin >> t ; 
	while(t--)
		solve() ; 
	return 0 ; 
}

