#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;
    int N = S.size(),M = T.size();
    vec<int> A(N+1),B(M+1);
    for(int i=0;i<N;i++){
        int c = (S[i]=='A'? 1:2);
        A[i+1] = A[i]+c;
    }
    for(int i=0;i<M;i++){
        int c = (T[i]=='A'? 1:2);
        B[i+1] = B[i]+c;
    }
    int Q;
    cin >> Q;
    while(Q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int x = A[b+1]-A[a],y = B[d+1]-B[c];
        cout << (x%3==y%3? "YES\n":"NO\n");
    }
}