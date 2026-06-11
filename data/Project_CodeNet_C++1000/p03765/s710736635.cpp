
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    1e9+7;
vector<vector<int> > nxt;
string s,t;
int n,m;
int pre1[N+5],pre2[N+5];
int main()
{  fast
 cin>>s>>t;
 n=s.size();
 m=t.size();
 for(int i=0;i<n;i++)
 {
 	pre1[i+1]+=pre1[i];
 	if(s[i]=='A')
 	pre1[i+1]++;
 	else
 	pre1[i+1]+=2;
 }
 for(int i=0;i<m;i++)
 {
 	pre2[i+1]=pre2[i];
 	if(t[i]=='A')
 	pre2[i+1]++;
 	else
 	pre2[i+1]+=2;
 }
 int q;
 cin>>q;
 while(q--)
 {
 	int a,b,c,d;
 	cin>>a>>b>>c>>d;
 	if((pre1[b]-pre1[a-1])%3==(pre2[d]-pre2[c-1])%3)
	puts("YES\n");
	else
	puts("NO\n");
 }
}
