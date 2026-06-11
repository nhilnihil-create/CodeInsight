#include "bits/stdc++.h"
using namespace std;

// GNU C Compiler
//template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }


/*
--------------------------------------------

	type

--------------------------------------------
*/
using LL = long long;
using ULL = unsigned long long;
//using pair<T1, T2> = p12;

/*
--------------------------------------------

	container

--------------------------------------------
*/
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())

/*
--------------------------------------------

	repetition

--------------------------------------------
*/
#define REP(n) for(int i=0; i<n; i++)
#define REPj(n) for(int j=0; j<n; j++)
#define REPinit(a,n) for(int i=a; i<n; i++)
#define REPinitj(a,n) for(int j=a; j<n; j++)

//algorithm
//#define SORT(c) sort((c).begin(),(c).end())

/*
--------------------------------------------

	constant

--------------------------------------------
*/
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

/*

	Optimizer

*/
//#pragma GCC optimize("Ofast")

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;

	int s_length = s.size();

	if((s.size() % 2 == 0) ^ (s[0] == s[s_length - 1])) {
		cout  << "Second" << endl;
	}
	else {
		cout  << "First" << endl;
	}

  return 0;
}
