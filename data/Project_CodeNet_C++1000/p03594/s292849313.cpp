#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define mod 1000000007
using namespace std;
typedef long long ll;
bool chmax(ll &a,ll b){
    if(a>b)return 0;
    a=b; return 1;
}
bool chmin(ll &a,ll b){
    if(a<b)return 0;
    a=b; return 1;
}

#define N 100010
ll h,w,d;
ll c[510][510];
int main(){
    cin>>h>>w>>d;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
	ll x=(i+j)%(2*d); if(x<0)x+=2*d;
	ll y=(i-j)%(2*d); if(y<0)y+=2*d;
	c[i][j]=0;
	if(x<d)c[i][j]++;
	if(y<d)c[i][j]+=2;
    }
    for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
	    string s="RYGB";
	    cout<<s[c[i][j]];
	}cout<<endl;
    }
}

