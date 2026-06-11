#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string s;
int main(){
    cin>>s;
    for(ll i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
        if(i==s.length()-2)continue;
        if(s[i]==s[i+2]){
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }
    }
    cout<<"-1 -1"<<endl;
    return 0;
}