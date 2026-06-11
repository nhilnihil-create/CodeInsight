#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=300005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N;cin>>N;
    
    if(N<=100){
        cout<<2*N<<endl;
        for(int i=0;i<N;i++) cout<<N-i<<" ";
        for(int i=0;i<N;i++) cout<<i+1<<" ";
        cout<<endl;
        return 0;
    }
    
    ll rem=N-100;
    
    vector<int> ans(200);
    for(int i=0;i<100;i++) ans[i]=100-i;
    for(int i=100;i<200;i++) ans[i]=i-100+1;
    
    ll last=99;
    for(int d=0;d<40;d++){
        ll move=min(last,rem);
        if((move&1)!=(rem&1)) move--;
        
        for(int i=0;i<100;i++){
            if(ans[i]==d+1){
                ans.erase(ans.begin()+i);
                ans.insert(ans.begin()+i-move,d+1);
                break;
            }
        }
        
        last=move-1;
        rem-=move;
        rem/=2;
        
        if(rem==0) break;
    }
    cout<<200<<endl;
    for(int i=0;i<200;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

