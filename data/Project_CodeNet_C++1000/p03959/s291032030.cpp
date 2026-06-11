#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define debug(x) cout << #x << ": " << x << endl;
#define popcnt __builtin_popcount


int main() {
    int N; cin>>N;
    vector<int> T(N), A(N), patT(N), patA(N);
    for (int i = 0; i < N; i++) cin>>T[i];
    for (int i = 0; i < N; i++) cin>>A[i];
    if(T[N-1]!=A[0]){
        cout<<0<<endl;
        return 0;
    }

    patT[0]=1; patA[N-1]=1;
    int nowmxT=T[0], nowmxA=A[N-1];

    for(int i = 1; i < N; i++)
    {
        if(nowmxT==T[i]){
            patT[i]=nowmxT;
        }else if(nowmxT<T[i]){
            nowmxT=T[i];
            patT[i]=1;
            if(A[i]<T[i]){
                cout<<0<<endl;
                return 0;
            }
        }
    }

    for(int i = N-2; i >= 0; i--)
    {
        if(nowmxA==A[i]){
            patA[i]=nowmxA;
        }else if(nowmxA<A[i]){
            nowmxA=A[i];
            patA[i]=1;
            if(A[i]>T[i]){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    
    ll res = 1LL;
    for(int i = 0; i < N; i++)
    {
        res*=(ll)min(patT[i], patA[i]);
        res%=MOD;
    }
    cout<<res<<endl;

    return 0;
}