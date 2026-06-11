#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define M2 100000007
#define F first
#define S second
#define PB push_back
#define INFL 1000000000000000000
#define INF 1000000000
bool ok[500],tmp[500];
int ans;
string s;
int main(void){
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		for(int j='a';j<='z';j++)ok[j]=true;
		for(int j=0;j<n-i;j++){
			for(int k='a';k<='z';k++)tmp[k]=false;
			for(int k=j;k<=j+i;k++)tmp[s[k]]=true;
			for(int k='a';k<='z';k++)ok[k]&=tmp[k];
		}
		bool p=false;
		for(int j='a';j<='z';j++)p|=ok[j];
		if(p){
			printf("%d\n",i);
			return 0;
		}
	}
}
