#include <bits/stdc++.h> 
using namespace std;
const int maxn=1e5+5;
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
cin>>a;
for(i=0;i<a;i++){
	cin>>z[i];
	mp[z[i]]=i;
}
sort(z,z+a);
b=0;
for(i=0;i<a;i++){
	if(i%2!=mp[z[i]]%2){
		b++;
	}
}
cout<<b/2<<endl;
return 0;}
