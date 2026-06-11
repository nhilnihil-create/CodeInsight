#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	vector<vector<string>> v(h, vector<string>(w));
	rep(i,h){
		rep(j,w){
			cin>>v[i][j];
		}
	}
	int r,c;
	rep(i,h){
		rep(j,w){
			if(v[i][j]=="snuke"){
				r=i;
				c=j;
			}
		}
	}
	vector<char> a(26);
	rep(i,26) a[i]='A'+i;
	cout<<a[c]<<r+1<<endl;
}