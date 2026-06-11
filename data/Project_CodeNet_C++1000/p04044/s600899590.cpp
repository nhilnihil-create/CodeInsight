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
    
    int n,l;
    cin>>n>>l;
    string s[111];
    FOR(i,0,n){
        cin>>s[i];
    }
    
    sort(s,s+n);
    
    string res="";
    FOR(i,0,n)
        res+=s[i];
    
    cout<<res<<"\n";


	return 0;
}