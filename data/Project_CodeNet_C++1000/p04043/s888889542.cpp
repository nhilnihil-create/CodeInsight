#include<bits/stdc++.h>
using namespace std;

//--> definitions
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,a,b) for(int i=b-1;i>=a;i--)

//--> typedef
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<pii,int> piii;
typedef tuple<int,int,int> tiii;

#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define INF 1e9

const int maxN = 1e4+11;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    int a,b,c;
    cin>>a>>b>>c;
    int cnt1=0,cnt2=0;
    if(a==5) cnt1++;
    if(b==5) cnt1++;
    if(c==5) cnt1++;
    if(a==7) cnt2++;
    if(b==7) cnt2++;
    if(c==7) cnt2++;
    
    if(cnt1==2 && cnt2==1) cout<<"YES\n";
    else cout<<"NO\n";


	return 0;
}