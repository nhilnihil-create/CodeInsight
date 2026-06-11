#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 1000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;

int n,m,h,w;
string a[111];
int cnt[26];
bool flag[111][111];
int dbcnt,scnt,ncnt;

signed main(){
	 cin>>h>>w;
	 rep(i,h)cin>>a[i];
	 rep(i,h){
	 	rep(j,w){
	 		cnt[(char)a[i][j]-'a']++;
	 	}
	 }
	 rep(i,h){
	 	rep(j,w){
	 		if(flag[i][j] || flag[i][w-j-1] || flag[h-i-1][j]  || flag[h-i-1][w-j-1])continue;
	 		if(i==h-i-1 && j==w-j-1){
	 			flag[i][j]=true;
	 			dbcnt++;
	 		}
	 		else if(i==h-i-1){
	 			flag[i][j]=true;
	 			flag[i][w-j-1]=true;
	 			scnt++;
	 		}
	 		else if(j==w-j-1){
	 			flag[i][j]=true;
	 			flag[h-i-1][j]=true;
	 			scnt++;
	 		}
	 		else{
	 			flag[i][j]=true;
	 			flag[h-i-1][j]=true;
	 			flag[i][w-j-1]=true;
	 			flag[h-i-1][w-j-1]=true;
	 			ncnt++;
	 		}
	 	}
	 }
	 //DEB(dbcnt)END DEB(scnt)END DEB(ncnt)END
	 int cont=0;
	 do{
	 	cont=0;
	 	rep(i,26){
	 		if(cnt[i]%2==1 && dbcnt>0){
	 			cnt[i]--;
	 			dbcnt--;
	 			cont=1;
	 		}
	 	}
	 }while(cont==1);
	 
	 if(dbcnt%2==0)scnt+=dbcnt/2;
	 do{
	 	cont=0;
	 	rep(i,26){
	 		if(cnt[i]%4==2 && scnt>0){
	 			cnt[i]-=2;
	 			scnt--;
	 			cont=1;
	 		}
	 	}
	 }while(cont==1);
	 if(scnt%2==0)ncnt+=scnt/2;
	 do{
	 	cont=0;
	 	rep(i,26){
	 		if(cnt[i]%4==0 && cnt[i]>0 && ncnt>0){
	 			cnt[i]-=4;
	 			ncnt--;
	 			cont=1;
	 		}
	 	}
	 }while(cont==1);
	 int f=1;
	 rep(i,26){
	 	if(cnt[i])f=0;
	 	//ARDEB(i,cnt)END
	 }
	 if(f)cout<<"Yes"<<endl;
	 else cout<<"No"<<endl;
}
