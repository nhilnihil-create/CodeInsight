#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?2e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int n,m,d;
	cin>>n>>m>>d;
	vs in(1010,string(1010,' '));
	if(d%2){
		rep(i,n)rep(j,m)if((i+j)%2)in[i][j]='R';
		else in[i][j]='Y';
	}else{
		int q=1;
		rep(i,1010){
			if(i%d==0)q^=1;
			int cnt=1+(i/2)%(d/2);
			int p=0;
			int x=0,y=i;
			if(!q){
				while(y>=0){
					if(!p)in[x][y]='R';
					else in[x][y]='Y';
					cnt--;
					if(cnt==0){
						cnt=d/2;
						p^=1;
					}
					x++;y--;
				}
			}else{
				while(y>=0){
					if(!p)in[x][y]='B';
					else in[x][y]='G';
					cnt--;
					if(cnt==0){
						cnt=d/2;
						p^=1;
					}
					x++;y--;
				}
			}
			i++;
		}
	}
	rep(i,n)rep(j,m)if(in[i][j]==' ')in[i][j]=in[i+1][j];
	rep(i,n)cout<<in[i].substr(0,m)<<endl;
	
}






