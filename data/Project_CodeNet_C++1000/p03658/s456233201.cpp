#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <cstdint>
#include <istream>
#include <sstream>
#include <cctype>
#include <functional>
#define fore(i,x,y) for(ll i=(x);i<(y);i++)
#define disp(a) cout << a << endl;
typedef long long ll;
using namespace std;
int main()
{
	int N,K,ANS=0;
	vector<int>V;
	cin>>N>>K;
	fore(i,0,N){
		int t;
		cin >> t;
		V.push_back(t);
	}
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	fore(i,0,K){
		ANS=ANS+V[i];
	}
	cout << ANS << endl;
}