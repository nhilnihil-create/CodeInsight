#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	string A;
	cin>>A;
	
	vector<vector<int>> next(A.size()+1,vector<int>(26,A.size()+1));
	{
		vector<int> temp(26,A.size()+1);
		for(int i=A.size()-1;i>=0;i--){
			next[i+1] = temp;
			temp[A[i]-'a'] = i+1;
		}
		next[0] = temp;
	}
	
	vector<int> dis(A.size()+2,Inf);
	dis[0] = 0;
	for(int i=0;i<next.size();i++){
		for(int j=0;j<26;j++){
			int to = next[i][j];
			dis[to] = min(dis[to],dis[i]+1);
		}
	}
	
	vector<vector<bool>> valid_edge(A.size()+1,vector<bool>(26,false));
	vector<bool> valid_vertex(A.size()+2,false);
	valid_vertex.back() = true;
	for(int i=valid_edge.size()-1;i>=0;i--){
		for(int j=0;j<26;j++){
			int to = next[i][j];
			if(!valid_vertex[to])continue;
			if(dis[i]+1==dis[to]){
				valid_vertex[i]=true;
				valid_edge[i][j] = true;
			}
		}
	}
	
	string ans = "";
	int now = 0;
	while(now!=A.size()+1){
		for(int i=0;i<26;i++){
			if(valid_edge[now][i]){
				ans += 'a'+i;
				now = next[now][i];
				break;
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}