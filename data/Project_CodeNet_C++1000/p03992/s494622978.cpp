#include <bits/stdc++.h>

using namespace std;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)


int main(void){

	string S; cin >> S;
	REP(i,4) cout << S[i];
	cout << " ";
	FOR(i,4,12) cout << S[i];
	cout << endl;


	return 0;

}
