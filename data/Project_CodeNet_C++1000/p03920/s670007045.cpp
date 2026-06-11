#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    bool maki=false;
    int mi=0,ma=1e4,mid=(mi+ma)/2;
    while(mi!=mid){
        if(mid*(mid+1)/2==n){
            maki=true;
            break;
        }
        else if(mid*(mid+1)/2<n){
            mi=mid;
        }
        else{
            ma=mid;
        }
        mid=(ma+mi)/2;
    }
    if(maki){
        for(int i=1;i<=mid;i++){
            cout << i<<endl;
        }
    }else{
        int x=ma*(ma+1)/2-n;
        for(int i=1;i<=ma;i++){
            if(x!=i){
                cout << i<<endl;
            }
        }
    }
    return 0;
}
