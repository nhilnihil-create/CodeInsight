#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> A;
set<int> S;

int main()
{
    cin>>N;
    int a;
    for(int i=1; i<=N; i++)
    {
        cin>>a;
        A.push_back({a, i});
    }
    sort(A.begin(), A.end());
    S.insert(0);
    S.insert(N+1);
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        auto it=S.lower_bound(A[i].second);
        auto pit=prev(it);
        long long l=A[i].second-*pit;
        long long r=*it-A[i].second;
        ans+=1LL*l*r*A[i].first;
        S.insert(A[i].second);
    }
    cout<<ans;
    return 0;
}
