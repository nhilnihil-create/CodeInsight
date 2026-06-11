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
    ll gCnt=0;
    ll N=s.length();
    for(auto c:s){
        if(c=='g')gCnt++;
    }
    cout<<gCnt-(N+1)/2<<endl;
    return 0;
}