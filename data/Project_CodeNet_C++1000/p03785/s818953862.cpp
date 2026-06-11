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
    ll N, C, K;
    ll t;
    cin>>N>>C>>K;
    vector<ll> T;
    rep(i, N){
        cin>>t;
        T.push_back(t);
    }
    sort(all(T));
    ll count=1, mem=1;
    ll thc=T[0];
    rep1(i, N-1){
        if(T[i]>thc+K || mem>=C){
            mem=0;
            thc=T[i];
            count++;
        }
        mem++;
        //cout<<mem<<sp<<thc<<endl;
    }
    cout<<count<<endl;
    return 0;
}
