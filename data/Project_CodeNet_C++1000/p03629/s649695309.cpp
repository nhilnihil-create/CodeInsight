#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX=2e5+5;
int pom[MAX][26];
pii father[MAX];
bool O[MAX];
int last[26];
string ans="";
queue<int>q;
int32_t main()
{
  BOOST;
  string s;
  cin>>s;
  int n=sz(s);
  fill(last,last+26,n+1);
  for (int i=n-1;i>=0;i--){
  	for (int j=0;j<26;j++)pom[i+1][j]=last[j];
  	last[s[i]-'a']=i+1;
  }
  for (int i=0;i<26;i++)pom[0][i]=last[i];
  O[0]=true;
  q.push(0);
  while (!q.empty()){
  	int akt=q.front();
  	q.pop();
  	if (akt==n+1){
  		break;
  	}
  	for (int i=0;i<26;i++){
  		int nekst=pom[akt][i];
  		//cout<<"TERAZ "<<akt<<" "<<char(i+97)<<" "<<nekst<<"\n";
  		if (!O[nekst]){
  			O[nekst]=true;
  			q.push(nekst);
  			father[nekst]=mp(akt,i);
  		}
  	}
  }
  
  int akt=n+1;
  while (akt){
  	ans+=char(97+father[akt].nd);
  	akt=father[akt].st;
  }
  
  
  
  
  reverse(ans.begin(),ans.end());
  cout<<ans;
  return 0;
}
