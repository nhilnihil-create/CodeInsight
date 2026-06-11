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
    ll count=0;
    cin>>N;
    vector<ll> s;
    ll S;
    rep(i, N){
        cin>>S;
        count+=S;
        s.push_back(S);
    }
    if(count%10!=0){
        cout<<count<<endl; return 0;
    }
    sort(all(s));
    ll dec=count;
    rep(i, N){
        if(s[i]%10!=0){
            dec=s[i];
            break;
        }
    }
    cout<<count-dec<<endl;
    return 0;
}
