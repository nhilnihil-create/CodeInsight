#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define MAX_N 1002
using namespace std;

typedef long long ll;
typedef pair<int,int> P1;
typedef pair<P1,ll> P2;
typedef pair<double,int> Pdi;
const ll INF=100000000000000001;
int dp1[MAX_N][MAX_N]={};
int dp2[MAX_N][MAX_N]={};
bool d[MAX_N]={};
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
priority_queue<Pdi,vector<Pdi>,greater<Pdi>> que;
vector<P1> v;
P2 xy[MAX_N]={};

double calc(int xx1,int xx2,int yy1,int yy2){
	double f=pow((double)xx1-(double)xx2,2)+pow((double)yy1-(double)yy2,2);
	return pow(f,0.5);
}
int main() {
	int h,w;
	cin>>h>>w;
	rep(i,h*w){
		string s;
		cin>>s;
		if(s=="snuke"){
			char c=i%w+'A';
			cout<<c<<i/w+1<<endl;
			return 0;
		}
	}
	return 0;
}
