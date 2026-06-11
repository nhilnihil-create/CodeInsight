#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.2")

#define all(x) (x).begin(),(x).end()

long long inp(){
    long long x;
    cin >> x;
    return x;
}

void opting(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

const long long maxn = 1e5 + 69, lg = 19;
long long A[maxn];
int n;
bool solve(){
    long long O, E;
    O = E = 0;
    long long G = 0;

    for(int i = 0; i < n; i++){
        if(A[i] & 1)
            O++;
        else
            E++;
        G = __gcd(G, A[i] - (A[i] & 1));
    }

    if(E & 1)
        return 1;
    if(O > 1)
        return 0;
    for(long long i= 0; i < n; i++)
        if(A[i] == 1)
            return 0;
        else
            A[i] = (A[i] - (A[i] & 1)) / G;
    return !solve();
}


int main(){
    opting();
    n = inp();
    for(long long i = 0; i < n; i++) cin >> A[i];//A.push_back(inp());//, cout << n << endl;
    if(solve())
        cout <<"First";
    else
        cout <<"Second";
}
