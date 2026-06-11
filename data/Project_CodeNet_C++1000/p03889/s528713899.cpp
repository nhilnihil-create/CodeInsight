
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<limits>
#include<iterator>
#include<iterator>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0; i<n; i++)
#define INF (1<<20)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ll, char> plc;

int main()
{
	string s1,s2="";
	cin >> s1;

	for (int i =s1.size()-1; i >=0; i--) {
		if (s1[i] == 'b') s2 += 'd';
		else if (s1[i] == 'd')s2 += 'b';
		else if (s1[i] == 'p')s2 += 'q';
		else if (s1[i] == 'q') s2 += 'p';
		else s2[i] += s1[i];
	}
	
	if (s1 == s2)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}