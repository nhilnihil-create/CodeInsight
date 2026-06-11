#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;

string s[30][30];

int main(void){
	int i,j;

	int H,W;
	cin >> H >> W;
	for(i=1;i<=H;i++) for(j=1;j<=W;j++) cin >> s[i][j];
	for(i=1;i<=H;i++) for(j=1;j<=W;j++) if(s[i][j]=="snuke"){
		cout << (char)('A'+j-1) << i << endl;
	}

	return 0;
}
