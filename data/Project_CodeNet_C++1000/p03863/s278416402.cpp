#include <bits/stdc++.h>
//#pragma GCC optimize "-O3"
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll infll=(1ull<<63)-1;
const int inf=(1ull<<31)-1;
bool q=true;
string a;

int main()
{
	//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(18);
	cin>>a;
	if (a[0]==a[a.size()-1]){
		if (a.size()&1)
			q=false;
	}
	else {
		if (!(a.size()&1))
			q=false;
	} 
	cout<<(q?"First":"Second");
	return 0;
}