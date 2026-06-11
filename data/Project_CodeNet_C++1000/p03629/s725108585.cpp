#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}

const int inf=1e9+10;
const int maxn=2e5+10;

char s[maxn],ans[maxn];
string s2;
int n,nxt[maxn][30],cnt[maxn];
bool f[maxn];

int main(){
	cin>>s2;
	for(int i=0;i<s2.size();i++) s[i+1]=s2[i];
	n=(int)s2.size();
	for(int i=0;i<maxn;i++) for(int j=0;j<30;j++) nxt[i][j]=n+1;
	for(int i=0;i<26;i++){
		int lst=n+1;
		for(int j=n;j>=0;j--){
			nxt[j][i]=lst;
			if(j!=0&&s[j]=='a'+i) lst=j;
		}
	}
	for(int i=0;i<maxn;i++) cnt[i]=-1;
	int cs=0;
	for(int i=n;i>=0;i--){
		bool flag=1;
		for(int j=0;j<26;j++) if(f[j]==0) flag=0;
		if(flag){
			cs++;
			for(int j=0;j<26;j++) f[j]=0;
		}
		cnt[i]=cs;
		if(i!=0) f[s[i]-'a']=1;
	}
	int len=cnt[0]+1,pos=0;
	for(int i=0;i<len;i++){
	//	cout<<pos<<" ";
		for(int j=0;j<26;j++){
			int np=nxt[pos][j];
		//	cout<<cnt[np]<<" "<<len-i-1<<endl;
			if(cnt[np]<len-i-1){
				ans[i]='a'+j;
				pos=np;
				break;
			}
		}
	}
//	cout<<endl;
	string t=(string)ans;
	cout<<t<<endl;
	return 0;
}
