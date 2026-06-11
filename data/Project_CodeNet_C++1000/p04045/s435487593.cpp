#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k;
    cin>>n>>k;
    vector<char> d(k);
    rep(i,k) cin>>d[i];

    while(1){
        string x=to_string(n);
        bool ok=true;
        rep(i,x.size()){
            rep(j,k){
                if(x[i]==d[j]){
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            cout<<n<<endl;
            return 0;
        }

        n++;
    }

} 
