#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N,ma,mb;cin>>N>>ma>>mb;
    vector<pair<pair<int,int>,int>> v;
    vector<pair<int,int>> v1,v2;
    int a,b,c;
    REP(i,N){
        cin>>a>>b>>c;
        v.push_back(make_pair(make_pair(a,b),c));
    }
    REP(i,1<<(N/2)){
        int ta=0,tb=0,tc=0;
        REP(j,(N/2)){
            if((i>>j)&1){
            ta+=v[j].first.first;
            tb+=v[j].first.second;
            tc+=v[j].second;
            }
        }
        v1.push_back(make_pair(mb*ta-ma*tb,tc));
    }
    REP(i,1<<(N-(N/2))){
        int ta=0,tb=0,tc=0;
        REP(j,(N-(N/2))){
            if((i>>j)&1){
            ta+=v[j+N/2].first.first;
            tb+=v[j+N/2].first.second;
            tc+=v[j+N/2].second; }           
        }
        v2.push_back(make_pair(ma*tb-mb*ta,tc));
    }
    sort(all(v1));
    sort(all(v2));
    int res=1<<30;
    pair<int,int> p=make_pair(0,1);
    int ind=lower_bound(all(v1),p)-v1.begin();
    if(ind != (int)v1.size() && v1[ind].first == 0) res= v1[ind].second;
    ind = (int)(lower_bound(all(v2),p)-v2.begin());
    if(ind != (int)v2.size() && v2[ind].first == 0) res= min(res,v2[ind].second);
    REP(i,(int)(v1.size())){
        ind = (int)(lower_bound(all(v2),make_pair(v1[i].first,1))-v2.begin());
        if(ind != (int)v2.size() && v2[ind].first==v1[i].first) res=min(res,v1[i].second+v2[ind].second);
    }

    cout<< (res==(1<<30)?-1:res )<<endl;
    return 0;
}