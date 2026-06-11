#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    int ma=0,ans;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        if(ma < a){
            ma = a;
            ans=a+b;
        }
    }

    cout<<ans<<endl;
    return 0;
}