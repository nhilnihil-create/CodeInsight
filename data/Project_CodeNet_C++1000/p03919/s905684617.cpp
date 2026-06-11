#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;

int main(){
	int H,W;
	cin>>H>>W;
	string S[26][26];
	rep(i,H)rep(j,W)cin>>S[i][j];
  
	int ansH,ansW;
	rep(i,H)rep(j,W){
		bool snuke=true;
		if(S[i][j][0]!='s')snuke=false;
		if(S[i][j][1]!='n')snuke=false;
		if(S[i][j][2]!='u')snuke=false;
		if(S[i][j][3]!='k')snuke=false;
		if(S[i][j][4]!='e')snuke=false;
		if(snuke){
			ansH=i;
			ansW=j;
			break;
		} 
	}
	char x='A'+ansW;
	cout<<x;
	cout<<ansH+1;
}