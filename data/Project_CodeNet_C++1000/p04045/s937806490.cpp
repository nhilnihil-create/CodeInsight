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
    
    int n;
    cin>>n;
    
    int k;
    cin>>k;
    
    int a[10];
    memset(a,1,sizeof(a));
    FOR(i,0,k){
        int j;
        cin>>j;
        a[j]=0;
    }
    
    while(1){
        bool ok=false;
        int x=n;
        while(x){
            int rem=x%10;
            if(a[rem]==0) {
                ok = true ;
                break;
            }
            x=x/10;
        }
        if(!ok) break;
        ++n;
    }
    
    cout<<n<<"\n";


	return 0;
}