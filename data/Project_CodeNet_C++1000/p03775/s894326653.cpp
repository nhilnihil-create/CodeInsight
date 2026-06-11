#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n;
    cin >> n;
    ll nakami = 10000000000;
    rep(i,1,sqrt(n)+1){
        if(n%i==0){
            ll other = n/i;
            nakami = min(nakami,other);
        }
    }
    int keta = 0;
    while(nakami!=0){
        nakami/=10;
        keta++;
    }
    cout<<keta<<endl;
    return 0;
}
