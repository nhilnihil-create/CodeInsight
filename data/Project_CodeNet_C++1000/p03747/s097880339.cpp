#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

int main(){
    int N;
    LL L,T;
    cin >> N >> L >> T;
    vector<LL> X,W;
    vector<P> last;
    bool c=false;
    for(int i=0;i<N;i++){
        LL x,w;
        cin >> x >> w;
        X.pb(x);
        W.pb(w);
        if(w==1) last.pb(P((x+T)%L,i));
        else last.pb(P((L+x-(T%L))%L,i));
        if(last[i].fs==last[0].fs&&i!=0&&W[0]==1) c=true;
    }
    LL count=0;
    for(int i=1;i<N;i++){
        if(W[i]==W[0]) continue;
        else{
            if(W[0]==1){
                count+=(2*T)/L;
                if(((2*T%L))>=(X[i]-X[0])) count++;
            }
            else{
                count-=(2*T)/L;
                if(((2*T%L))>=(L-(X[i]-X[0]))) count--;
            }
        }
    }
    sort(ALL(last));
    int u=0;
    for(int i=0;i<N;i++){
        if(last[i].sc==0){
            u=i;
            break;
        }
    }
    int t=(N+u-((N+(count%N))%N))%N;
    if(c) t++;
    for(int i=0;i<N;i++){
        cout << last[(t+i)%N].fs << endl;
    }
    return 0;
}
