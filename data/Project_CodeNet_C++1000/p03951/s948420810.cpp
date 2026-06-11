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
    ll N;
    string s, t;
    ll Maxim=0;
    cin>>N>>s>>t;
    rep(i, s.size()){
        bool ok=true;
        reps(j, i, s.size()){
            if(s[j]!=t[j-i]) ok=false; //out<<i<<sp<<j<<endl;
        }
        if(ok) Maxim=max(Maxim, (ll)s.size()-i);
    }
    cout<<2*N-Maxim<<endl;
    return 0;
}
