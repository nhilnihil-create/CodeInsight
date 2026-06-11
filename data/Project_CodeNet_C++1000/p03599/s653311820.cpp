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

int possoS[4000];
int possoW[4000];

int main(void){
    ll A, B , C, D, E, F;
    cin>>A>>B>>C>>D>>E>>F;
    
    MEMSET(possoS, 0);
    rep(i, 3001){
        rep(j, 1501){
            if(i*C+j*D>F) break;
            else possoS[i*C+j*D]=1;
        }
    }
    rep(i, 3001){
        rep(j, 1501){
            if(i*A*100+j*B*100>F) break;
            else possoW[i*A*100+j*B*100]=1;
        }
    }
    ll ansS=0, ansW=100*A;
    rep(W, 3001){
        if(possoW[W]==0) continue;
        if(W==0) continue;
        ll Limit=min(F-W, W/100*E);
        //cout<<Limit<<sp;
        rep(S, Limit+1){
            if(possoS[S]==1) if(ansS*(S+W)<S*(ansW+ansS)){
                ansW=W;
                ansS=S;
            }
        }
    }
    cout<<ansW+ansS<<sp<<ansS<<endl;
    return 0;
}
