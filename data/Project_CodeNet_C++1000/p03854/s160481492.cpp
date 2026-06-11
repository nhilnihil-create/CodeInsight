#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
string s;
int main(){
	cin>>s;
	int n=s.size();
	if(n<5) puts("NO");
	else {
		int f=1;
		for(int i=n-1;~i;){
			if(i-4>=0&&s.substr(i-4,5)=="dream") i-=5;
			else if(i-4>=0&&s.substr(i-4,5)=="erase") i-=5;
			else if(i-5>=0&&s.substr(i-5,6)=="eraser") i-=6;
			else if(i-6>=0&&s.substr(i-6,7)=="dreamer") i-=7;
			else {
				f=0;
				break;
			}
		}
		puts(f?"YES":"NO");
	}
	return 0;
}