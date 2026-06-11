#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define SZ(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

int main() {
	string s;
	cin>>s;
	if (s.size()<4||s.substr(0,4)!="YAKI") puts("No");
	else puts("Yes");
}