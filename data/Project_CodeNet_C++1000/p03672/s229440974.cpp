/*I know about "bits/stdc++.h" 
But I am not using it for some technical issue*/

#include "iostream"
#include "algorithm"
#include "iomanip"
#include "vector"
#include "set"
#include "sstream"
#include "fstream"
#include "cstring"
#include "cmath"
#include "utility"
#include "map"
#include "bitset"
#include "cassert"
#include "deque"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define mod (int)1e9 + 7
#define For(i,a,n) for(i=a;i<n;i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
bool hbe(string st,int n){
	int h = n/2;
	string s1 = string(st.begin(),st.begin()+h), s2 = string(st.begin()+h,st.begin()+n);
	return !(s1 == s2);
}
void solve(string st){
	int n = st.size() - 1;
	if(n&1) n--;
	while(hbe(st,n)){
		n -= 2;
	}
	cout<<n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string st;
	cin>>st;
	solve(st);
  return 0;
}