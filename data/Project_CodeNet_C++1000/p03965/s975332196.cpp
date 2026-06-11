#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string s;
int main(){
    cin>>s;
    ll gCnt=0,pCnt=0;
    for(auto c:s){
        if(c=='g'){
            gCnt++;
        }else{
            pCnt++;
        }
    }
    cout<<(gCnt-pCnt)/2<<endl;
    return 0;
}