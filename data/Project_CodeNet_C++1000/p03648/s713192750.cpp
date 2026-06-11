#include <bits/stdc++.h>
using namespace std;

int main()
{
    long K; cin>>K;
    int n=50;
    vector<long> a(n);
    for(int i=0; i<n; ++i) a[i]=K/n+i;
    K%=n;
    for(int i=0; i<K; ++i) {
        a[i]+=n;
        for(int j=0; j<n; ++j) if (i!=j) --a[j];
    }
    cout<<n<<endl;
    for(auto e: a) cout<<e<<' ';
    cout<<endl;
}
