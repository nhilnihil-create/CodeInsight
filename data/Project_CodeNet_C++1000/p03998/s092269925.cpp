#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	vector<string>s(3);
	rep(i,3)cin>>s[i];
	vi as(3,0);
	as[0]=1;
	int ne =0;
	while(s[0].length()>=as[0]&&s[1].length()>=as[1]&&s[2].length()>=as[2]){
		ne = s[ne][as[ne]-1]-'a';
		as[ne]++;
	}
	char res[3]={'A','B','C'};
	rep(i,3){
		if(s[i].length()+1==as[i])cout<<res[i]<<endl;
	}
}