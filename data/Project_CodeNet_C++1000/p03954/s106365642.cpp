#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> P;
int A[200006];
int a[200006];
signed main(){
	int N;cin>>N;
	int n=N*2-1;
	rep(i,n)cin>>A[i];
	
	int lb=1,ub=n;
	while(ub-lb>1){
		int mi=(ub+lb)/2;
		rep(i,n){
			if(A[i]>=mi)a[i]=1;
			else a[i]=0;
		}
		
			vector<P>V;
			int now=a[0],cnt=0;
			rep(i,n){
				if(now==a[i])cnt++;
				else{
					V.push_back(P(now,cnt));
					now=a[i];cnt=1;
					}
				}
			V.push_back(P(now,cnt));
			
			stack<P>S;cnt=0;
			S.push(P(1^a[0],0));
			rep(i,V.size()){
				if(V[i].second==1)cnt++;
				else{
					if(cnt&1){
						P p=S.top();S.pop();
						p.second+=cnt+V[i].second;
						S.push(p);
						cnt=0;
						}
					else{
						P p=S.top();S.pop();
						p.second+=cnt/2;
						S.push(p);
						P p2=V[i];
						p2.second+=cnt/2;
						S.push(p2);
						cnt=0;
						}	
					}
				}
				
			if(cnt&1)S.push(P(a[n-1],cnt));
			else{
				S.push(P(a[n-1],cnt/2));
				S.push(P(1^a[n-1],cnt/2));
				}	
			int sum=0;
			int col=0;
			while(sum<N){
				P p3=S.top();S.pop();
				col=p3.first;
				sum+=p3.second;
				}	
			
			if(col)lb=mi;
			else ub=mi;	
		}
		cout<<lb<<endl;
	}
