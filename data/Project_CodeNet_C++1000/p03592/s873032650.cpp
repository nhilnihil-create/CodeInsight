#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=0;i<=m;i++)for(int j=0;j<=n;j++){
        if(j*(m-i)+(n-j)*i==c){
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout <<"No\n";
    return 0;
}
