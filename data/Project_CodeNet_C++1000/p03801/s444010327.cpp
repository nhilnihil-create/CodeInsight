#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003,INF=1<<30;

int main(){
    
    int N;cin>>N;
    
    vector<pair<ll,int>> A(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }
    
    sort(all(A));
    reverse(all(A));
    
    A.push_back(make_pair(0,-1));
    
    vector<ll> cnt(N);
    
    int mini=INF;
    
    for(int i=0;i<N;i++){
        if(A[i].first!=A[i+1].first){
            int j=A[i].second;
            mini=min(mini,j);
            cnt[mini]+=(A[i].first-A[i+1].first)*(i+1);
        }else mini=min(mini,A[i].second);
        //cout<<cnt[mini]<<endl;
    }
    
    for(int i=0;i<N;i++){
        cout<<cnt[i]<<endl;
    }
}
