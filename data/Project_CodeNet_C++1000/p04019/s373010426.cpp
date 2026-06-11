#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

int main (){
	string s;
	cin >> s;
	int cn=0,cw=0,cs=0,ce=0;
	rep (i,s.size()){
		if (s[i]=='N') cn++;
		if (s[i]=='W') cw++;
		if (s[i]=='S') cs++;
		if (s[i]=='E') ce++;
	}
	//cout << cn << " " << cs  << endl; 
	bool flag = true;
	
		if ((cn!=0&&cs==0)||(cn==0&&cs!=0)||(ce!=0&&cw==0)||(ce==0&&cw!=0)){
			flag = false;
		
	}
	if(flag)cout << "Yes" << endl;
	else cout << "No" << endl;
}


