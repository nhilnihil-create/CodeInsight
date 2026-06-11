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

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    string A;
    cin>>A;
    ll co[26];
    MEMSET(co, 0);
    ll ans=1;
    rep(i, A.size()){
        ans+=i-co[A[i]-'a'];
        co[A[i]-'a']++;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
