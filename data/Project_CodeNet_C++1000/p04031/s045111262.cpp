#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n,c;
    int a;int b=1e9;
    cin >> n;
    vector<int> v;
    for (int i=0;i<n;++i){
        cin >> c;
        v.push_back(c);
    }

    for (int i=-100;i<=100;++i){
        int a=0;
        for (int j=0;j<n;++j){
            a += (v[j]-i)*(v[j]-i);

        }b = min(a,b);
    }
    cout << b;
    return 0;
}
