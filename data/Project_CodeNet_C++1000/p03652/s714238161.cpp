#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

int main() {
    int N,M; cin>>N>>M;

    queue<int> A[310];
    int a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin>>a; --a;
            A[i].push(a);
        }
    }

    vector<bool> del(M,false);

    int ans=N;

    for (int i = 0; i < M-1; ++i) {
        int cnt[310]={0};
        for (int j = 0; j < N; ++j) {
            cnt[A[j].front()]++;
        }
        int maxi=-1,maxino=-1;
        for (int j = 0; j < M; ++j) {
            if(cnt[j]>maxi){
                maxi=cnt[j];
                maxino=j;
            }
        }
        ans=min(ans,maxi);
        del[maxino]=true;
        for (int j = 0; j < N; ++j) {
            while(del[A[j].front()]) A[j].pop();
        }
    }

    cout<<ans<<endl;

    return 0;
}
