#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll A[10000];
int T[10000];
int main(){
    int N, K;
    cin >> N >> K;
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    sort(A, A+N);
    int right = N-1;
    int left = N-1;
    ll sum = A[N-1];
    while(1){
        if(sum >= K){
            sum -= A[right];
            T[right]++;
            right--;
        }
        else{
            ll tmps = sum;
            for(int i = left-1; i >= 0; i--){
                tmps += A[i];
                if(tmps < K) break;
                T[i]++;
                tmps -= A[i];
            }
            left--;
            if(left < 0) break;
            sum += A[left];
        }
    }


    for(int i = 1; i < N; i++){
        T[i] += T[i-1]; 
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(!T[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
