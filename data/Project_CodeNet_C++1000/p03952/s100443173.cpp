#include <bits/stdc++.h> 
using namespace std;
const int maxn=10e5+5;
const long long sg=1e10;
long long a,b,c,d,e,f,g,n,m,i,j,sdg[maxn],lili,t;
long long  x[maxn][10],z[maxn],v[101][101],h[maxn];
string p[maxn],s[maxn];
queue<int>q;
bool mark[maxn];
vector<long long> o[maxn],sgd;
map<long long,long long> mp;
char l[10][10],y;
int main(){
ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
cin>>a>>b;
if(b==1||b==2*a-1){
	cout<<"No"<<endl;
}
else{
	cout<<"Yes"<<endl;
	for(i=1;i<2*a;i++){
		z[i]=i;
	}
	swap(z[a],z[b]);
	swap(z[b-1],z[a-1]);
	swap(z[b+1],z[a+1]);
	if(b==a-1){
		swap(z[a],z[a+1]);
	}
	if(b==a+1){
		swap(z[a],z[a-1]);
	}
	for(i=1;i<2*a;i++){
		cout<<z[i]<<endl;
	}
}
return 0;}
