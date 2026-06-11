#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int ans[maxn];
int s[maxn];
typedef pair<int,int> ii;
priority_queue<ii> pq;
signed main() {
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++) {
        int a;
        cin>>a;
        pq.push(ii(a,i));
        s[i]=1;
    }
    while(pq.size()>1) {
        int t1=pq.top().first;
        int id1=pq.top().second;
        pq.pop();
        int t2=pq.top().first;
        int id2=pq.top().second;
        pq.pop();
        ans[id1]+=s[id1]*(t1-t2);
		pq.push(ii(t2,min(id1,id2)));
		s[min(id1,id2)]+=s[max(id1,id2)];
    }
    ans[1]+=n*pq.top().first;
    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<endl;
    return 0;
}
