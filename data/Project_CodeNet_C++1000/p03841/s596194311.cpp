#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int ans[N*N];
int x[N];

void no() {
    cout<<"No"<<endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> vp;

    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>x[i];
        vp.push_back({x[i], i});
        ans[x[i]] = i;
    }

    sort(vp.begin(), vp.end());
    int ptr = 1;
    for (int i=0; i<n; i++) {
        int pos = vp[i].first;
        int x = vp[i].second;

        for (int i=1; i<x; i++) {
            while(ans[ptr])    ptr++;
            if (ptr > pos)     no();
            ans[ptr] = x;
        }
    }

    reverse(vp.begin(), vp.end());
    ptr = n*n;
    for (int i=0; i<n; i++) {
        int pos = vp[i].first;
        int x = vp[i].second;

        for (int i=1; i<=n-x; i++) {
            while(ans[ptr])    ptr--;
            if (ptr < pos)     no();
            ans[ptr] = x;
        }
    }

    cout<<"Yes"<<endl;
    for (int i=1; i<=n*n; i++)  cout<<ans[i]<<" ";
}
