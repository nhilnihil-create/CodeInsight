#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;





int main()
{
    int N;
    cin >> N;

    mat A(N,vec(N));
    mat B(N,vec(N,10000000000));

    for(int i=0;i<N;++i) for(int j=0;j<N;++j)
    {
        cin >> A[i][j];
    }

    for(int k=0;k<N;++k) for(int i=0;i<N;++i) for(int j=0;j<N;++j)
    {
        if(i==k||k==j)continue;
        B[i][j] = min(B[i][j],A[i][k] + A[k][j]);
    }

    ll ans=0;
    for(int i=0;i<N;++i) for(int j=0;j<N;++j)
    {
        if(A[i][j]<B[i][j]) {ans += A[i][j];}
        if(A[i][j]>B[i][j])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans/2 << endl;
    return 0;
}