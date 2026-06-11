#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int n,x[510],a[250010]={};
		
int main(){
	cin >> n;
	REP(i,0,n){
		cin >> x[i]; x[i]--;
		a[x[i]]=i+1;
	}
	
	REP(i,0,n*n){
		if(a[i]){
			int c=a[i]-1;
			REP(j,0,i){
				if(!c) break;
				if(!a[j]) a[j]=a[i],c--;
			}
			if(c){cout << "No" << endl; return 0;}
		}
	}
	
	set<int> st; st.insert(0);
	RREP(i,n*n-1,0){
		if(!st.count(a[i])){
			st.insert(a[i]);
			int c=n-a[i];
			RREP(j,n*n-1,i){
				if(!c) break;
				if(!a[j]) a[j]=a[i],c--;
			}
			if(c){cout << "No" << endl; return 0;}
		}
	}	
	
	cout << "Yes" << endl;
	REP(i,0,n*n) cout << a[i] << " "; cout << endl;
	return 0;
}
