#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
int x[601];
LL ans[1000001];
typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >que;
bool used[602];
int main(){
	cin>>N;
	REP(i,N){
		used[i]=false;
	}
	REP(i,N*N){
		ans[i]=-1;
	}
	REP(i,N){
		cin>>x[i];
		x[i]--;
		ans[x[i]]=i;
		REP(j,i){
			que.push(P(x[i],i));
		}
	}
	/*REP(i,N*N){
		cout<<ans[i]+1;
		if(i!=N*N-1){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}*/
	REP(i,N*N){
		if(ans[i]==-1){
			if(que.empty()){
				cout<<"No"<<endl;
				return 0;
			}
			P p=que.top();
			que.pop();
			ans[i]=p.second;
			if(used[p.second]==true&&p.first!=1e9){
				cout<<"No"<<endl;
				return 0;
			}
		}else{
			REP(j,N-1-ans[i]){
				que.push(P(1e9,ans[i]));
			}
			used[ans[i]]=true;
		}
	}
	cout<<"Yes"<<endl;
	REP(i,N*N){
		cout<<ans[i]+1;
		if(i!=N*N-1){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	return 0;
}