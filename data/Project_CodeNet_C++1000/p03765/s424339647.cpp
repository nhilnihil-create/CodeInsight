#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <limits.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
using prique = priority_queue<int>;
const int MOD = 1000000007;

signed main(){
	string s,t;
	cin>>s>>t;
	int q;
	cin>>q;
	int as[114514]={},at[114514]={},bs[114514]={},bt[114514]={};
	for(int i=0;i<(int)s.size();i++){
		if(s[i]=='A'){
			as[i]=as[max(i-1,0)]+1;
			bs[i]=bs[max(i-1,0)];
		}else{
			bs[i]=bs[max(i-1,0)]+1;
			as[i]=as[max(i-1,0)];
		}	
	}
	for(int i=0;i<(int)t.size();i++){
		if(t[i]=='A'){
			at[i]=at[max(i-1,0)]+1;
			bt[i]=bt[max(i-1,0)];
		}else{
			bt[i]=bt[max(i-1,0)]+1;
			at[i]=at[max(i-1,0)];
		}	
	}
	for(int i=0;i<q;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ba=as[b-1]-as[a-2],bb=bs[b-1]-bs[a-2],ea=at[d-1]-at[c-2],eb=bt[d-1]-bt[c-2];
		int ca=ea-ba,cb=eb-bb;
		bool ans=false;
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				if((2*x-y)%3==(ca%3+3)%3&&(2*y-x)%3==(cb%3+3)%3)ans=true;

			}	
		}
		if(ans)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}