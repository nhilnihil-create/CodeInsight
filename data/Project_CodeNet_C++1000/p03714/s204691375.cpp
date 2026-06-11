#include <bits/stdc++.h>
using namespace std;
long long ans=-1e18;
int N;
int m[333333];
long long v[333333], w[333333],s1,s2;
priority_queue<int>pq1,pq2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<3*N;i++){
        cin>>m[i];
        if(i<N)pq1.push(-m[i]),s1+=m[i];
        if(i>=2*N)pq2.push(m[i]),s2+=m[i];
    }
    for(int i=N;i<=2*N;i++){
        v[i]=s1;
        s1+=m[i];
        pq1.push(-m[i]);
        s1+=pq1.top();
        pq1.pop();
    }
    for(int i=2*N-1;i>=N-1;i--){
        w[i]=s2;
        s2+=m[i];
        pq2.push(m[i]);
        s2-=pq2.top();
        pq2.pop();
    }
    for(int i=N;i<=2*N;i++){
        ans=max(ans,v[i]-w[i-1]);
    }
    cout<<ans;
 
    return 0;
}