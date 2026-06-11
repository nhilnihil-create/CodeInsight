#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//typedef pair<int, int> P;
//typedef pair<int, pair<int, int> > PP;

int main(){
  	int N;
	cin>>N;
	int A[300][300], B[300][300];
	rep(i,N)rep(j,N){
		cin>>A[i][j];
		B[i][j]=A[i][j];
	}
	
	rep(k,N)rep(i,N)rep(j,N)B[i][j]=min(B[i][j], B[i][k]+B[k][j]);
	
	bool rex=true;
	rep(i,N)rep(j,N)if(A[i][j]!=B[i][j])rex=false;
	if(!rex){
		cout<<-1<<endl;
		return 0;
	}
  	
	ll ans=0;
	rep(i,N)rep(j,N)if(i<j){
		bool nd=true;
		rep(k,N)if(k!=i && k!=j){
          	if(B[i][j]==B[i][k]+B[k][j])nd=false;
        }
		if(nd)ans+=(ll)B[i][j];
	}
	cout<<ans<<endl;
}