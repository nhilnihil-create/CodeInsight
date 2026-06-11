#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const int INF=1e7;
const LL LINF=1e18;

priority_queue<LL> pq;

int main(){
    int N;
    LL T;
    cin >> N >> T;
    LL a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    LL maxi=0;
    LL dist[N];
    for(int i=N-1;i>=0;i--){
        maxi=max(maxi,a[i]);
        dist[i]=maxi;
    }
    priority_queue<LL> pq;
    for(int i=0;i<N;i++){
        pq.push(dist[i]-a[i]);
    }
    LL ch=pq.top(),ans=0;
    while(1){
        if(ch==pq.top()){
            ans++;
            pq.pop();
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}

