#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int inf = 1e9;

int main() {
	string S;
	cin>>S;
	string ans = "No";
	if(S[0]=='Y'&&S[1]=='A'&&S[2]=='K'&&S[3]=='I')ans="Yes";
	cout<<ans<<endl;
}