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
const int MAX=1e5+10;

int main(){
	int N, M;
	cin>>N>>M;
	vi A[300];
	rep(i,N){
		rep(_,M){
			int a;
			cin>>a;
			A[i].push_back(a);
		}
	}
	int ans=1000;
	while(!A[0].empty()){
		multiset<int> st;
		set<int> er;
		rep(i,N) st.insert(A[i][0]);
		int tmp=0;
		for(auto it=st.begin(); it!=st.end(); it++)tmp=max(tmp, (int)st.count(*it));
		ans=min(ans, tmp);
		for(auto it=st.begin(); it!=st.end(); it++)if((int)st.count(*it)==tmp)er.insert(*it);
		for(auto it=er.begin(); it!=er.end(); it++){
          	int k=*it;
          	rep(i,N){
			
				auto itr=find(A[i].begin(), A[i].end(), k);
				A[i].erase(itr);
            }
		}
	}
	cout<<ans<<endl;
}