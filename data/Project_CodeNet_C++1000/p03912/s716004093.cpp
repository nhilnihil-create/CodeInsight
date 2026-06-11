#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <unordered_map>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;
unordered_map<ll, ll> val[200000];
ll num[200000];
int main(void){
    ll N, M;
    cin>>N>>M;
    ll X;
    MEMSET(num, 0);
    rep(i, N){
        cin>>X;
        num[X%M]++;
        val[X%M][X]++;
    }
    ll count=0;
    rep1(i, (M%2==0 ? M/2-1 : M/2)){
        ll count1=0, count2=0;
        //cout<<i<<sp<<M-i<<endl;
        for(auto itr : val[i]) count1+=itr.second/2;
        for(auto itr : val[M-i]) count2+=itr.second/2;
        count+=min(num[i], num[M-i]);
        //cout<<count<<endl;
        count+=max((ll)0, min((num[i]-num[M-i])/2, count1));
        //cout<<count<<endl;
        count+=max((ll)0, min((num[M-i]-num[i])/2, count2));
    }
    count+=num[0]/2;
    if(M%2==0) count+=num[M/2]/2;
    cout<<count<<endl;
    return 0;
}
