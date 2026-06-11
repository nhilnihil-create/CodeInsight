/*  
    Come feed the rain
	Cos I'm thirsty for your love
	Dancing underneath the skies of lust
	Yeah feed the rain...
	Cos without your love my life
	Ain't nothing but this carnival of rust
    _________________________
    _________________________
    816 Hours of Solitude
    Quarantine_Day : 34
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long int       ll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef pair<int, int>      pii;

#define pb(n)           push_back(n)
#define GSORT(v)        sort(v.begin(), v.end(), greater<int>())
#define SORT(v)         sort(v.begin(), v.end());
#define REV(v)          reverse(v.begin(), v.end());
#define db(a)           cout<<#a<<" = "<<a<<endl;
#define FIN             freopen("in.txt","r",stdin);
#define FOUT            freopen("out.txt","w",stdout);
#define REP(i,n)        for(int i = (int)(0); i < (int)(n); i++)
#define FOR(i, a, b)    for(int i = (int)a; i <= (int)b; i++)    

#define MAX 50005
#define MOD 1000000007

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, a, b; cin>>w>>a>>b;

	cout<<max(0, max(a, b) - (w+ min(a, b)))<<"\n";

	return 0;
}
