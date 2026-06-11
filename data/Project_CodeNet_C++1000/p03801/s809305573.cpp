#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

map<lli,lli> cnt;
map<lli,lli> minPos;

lli ans[100100];

void func(long long N, std::vector<long long> a){

    REP(i,0,N){
        cnt[a[i]]++;
        if(minPos.count(a[i])==0){
            minPos[a[i]]=i;
        }
        else{
            chmin(minPos[a[i]],(lli)i);
        }
    }

    //q.first num, second.first cnt, second.second minPos
    priority_queue<pair<lli,pair<lli,lli>>> q;
    
    for(auto e:cnt){
        q.push({e.first,{e.second,minPos[e.first]}});
    }

    while(q.size()>1){
        pair<lli,pair<lli,lli>> nowTop = q.top();
        q.pop();
        pair<lli,pair<lli,lli>> nexTop = q.top();
        q.pop();
        lli diffNum = nowTop.first - nexTop.first;
        ans[nowTop.second.second] += diffNum * nowTop.second.first;

        nexTop.second.first += nowTop.second.first;
        chmin(nexTop.second.second,nowTop.second.second);
        q.push(nexTop);
    }

    pair<lli,pair<lli,lli>> lasTop = q.top();

    ans[lasTop.second.second] += lasTop.first * lasTop.second.first;

    REP(i,0,N){
        cout<<ans[i]<<endl;
    }

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    func(N, std::move(a));
    return 0;
}
