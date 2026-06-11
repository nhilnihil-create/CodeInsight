#include<bits/stdc++.h>
using namespace std;

//#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>PII;
typedef vector<PII>Vll;
typedef vector<pair<int,pair<int,int> > >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>MP;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
signed main(){
  string str;
  cin>>str;
  int len=str.length();
  int pos1=-1,pos2=-1;
  for(int i=0;i<len-1;i++){
	  if(str[i]==str[i+1]){
		  pos1=i+1;
		  pos2=i+2;
		  break;
	  }
  }
  
  if(pos1==-1){
	  for(int i=0;i<len-2;i++){
		 if(str[i]==str[i+2]){
			 pos1=i+1;
			 pos2=i+3;
			 break;
		 }  
	  }
  }
  cout<<pos1<<" "<<pos2<<endl;
  
  return 0;
}
