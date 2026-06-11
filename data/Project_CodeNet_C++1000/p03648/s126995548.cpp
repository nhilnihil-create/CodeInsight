#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000000;
int main() {   
    ll k;
    cin>>k;
    ll n=50LL;
    cout<<n<<endl;
    ll a[51];
    for(ll i=0;i<n;i++){
        a[i]=(n-1)+(k/n);
    }
    for(ll i=0;i<k%n;i++){
        for(ll j=0;j<n;j++){
            if(i==j){
                a[j]+=n;
            }else{
                a[j]--;
            }
        }
    }
    for(ll i=0;i<n;i++){
        cout<<a[i];
        if(i==n-1){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
    getchar();
    getchar();
}

                           
