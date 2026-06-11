#include <math.h>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <iostream>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    FOR(i, 0, N){
        cin >> A[i];
    }
    int ans = N;
    sort(A.begin(),A.end());
    vector<vector<bool>> D(N+1,vector<bool>(K,false));
    D[N][0] = true;
    FOR(j,0,N){
        int i = N - j - 1;
        D[i][0] = true;
        if (A[i]>=K){
            ans = i;
            continue;
        }
        else {
            FOR(k,0,K){
                if (D[i+1][k]){
                    if (K-A[i]<=k){
                        ans = i;
                    }
                    D[i][k] = true;
                    if (k+A[i]<K){
                        D[i][k + A[i]] = true;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
