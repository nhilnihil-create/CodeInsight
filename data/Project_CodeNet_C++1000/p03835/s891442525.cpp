#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int k,s;
    cin>>k>>s;

    int ans=0;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
            int z=s-(x+y);
            if(0<=z && z<=k) ans++;
        }
    }

    cout<<ans<<endl;
}