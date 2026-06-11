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

using namespace std;
typedef long long int lli;
const int MAX=1e5+5;
const int INF=1e9;

int N;
vector<int> nb[MAX];
int fe[MAX];
int sn[MAX];


int main(){
	cin>>N;
	rep(i,N){
		int a,b;
		cin>>a>>b;
		nb[a].push_back(b);
		nb[b].push_back(a);
	}
	
	
	//bfsでfeの最小手数をカウント
	rep1(i,N)fe[i]=INF;
	queue<int> q1;
	q1.push(1);
	fe[1]=0;
	while(!q1.empty()){
		int v=q1.front();
		q1.pop();
		int l=nb[v].size();
		rep(j,l){
			int w=nb[v][j];
			if(fe[w]==INF){
				fe[w]=fe[v]+1;
				q1.push(w);
			}
		}
	}
	//bfsでsnの最小手数をカウント
	rep1(i,N)sn[i]=INF;
	queue<int> q2;
	q2.push(N);
	sn[N]=0;
		while(!q2.empty()){
		int v=q2.front();
		q2.pop();
		int l=nb[v].size();
		rep(j,l){
			int w=nb[v][j];
			if(sn[w]==INF){
				sn[w]=sn[v]+1;
				q2.push(w);
			}
		}
	}
//	rep1(i,N)cout<<fe[i]<<" ";
//  	cout<<endl;
//	rep1(i,N)cout<<sn[i]<<" ";
//  	cout<<endl;
  
	int wfe=0,wsn=0;
	rep1(i,N){
		if(fe[i]<=sn[i])wfe++;
		else wsn++;
	}
	if(wfe>wsn)cout<<"Fennec";
	else cout<<"Snuke";
}