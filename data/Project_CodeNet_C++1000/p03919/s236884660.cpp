#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<cctype>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long INF=1LL<<60;


int main(void){
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s;
	int j,i,h,w;
	cin>>h>>w;
	string snuke[h][w];
	for(i=0;i<h;i++)for(j=0;j<w;j++)cin>>snuke[i][j];
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(snuke[i][j]=="snuke"){
				cout<<(char)('A'+j)<<i+1<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}