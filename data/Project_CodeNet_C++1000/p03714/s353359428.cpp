#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define mod 1000000007


int main() {
    int N; cin >> N;
    vector<int> A(3*N);
    priority_queue<int ,vector<int>, greater<int>> LN;
    vector<ll> LS(N);
    priority_queue<int> RN;
    vector<ll> RS(N);
    ll lsum = 0;
    ll rsum = 0;
    for(int i=0; i<3*N; i++){
        cin >> A[i];
        if(i<N){
            lsum += A[i];
            LN.push(A[i]);
        }
        if(i>=2*N){
            rsum += A[i];
            RN.push(A[i]);
        }
    }
    
    for(int i=0; i<N; i++){
        LN.push(A[N+i]);
        if(i==0) LS[i] = lsum + A[N+i] - LN.top();
        else LS[i] = LS[i-1] + A[N+i] - LN.top();
        LN.pop();
    }
    
    for(int i=2*N-1; i>=N; i--){
        RN.push(A[i]);
        if(i==2*N-1) RS[2*N-1-i] = rsum + A[i] - RN.top();
        else RS[2*N-1-i] = RS[2*N-2-i] + A[i] - RN.top();
        RN.pop();
    }
    
    
    ll ans = 1LL<<60;
    ans *= -1;
    
    for(int i=N-1; i<2*N; i++){
        if(i==N-1) ans = max(ans, lsum - RS[i]);
        else if(i==2*N-1) ans = max(ans, LS[N-1] - rsum);
        else ans = max(ans, LS[i-N] - RS[2*N-2-i]);
    }
    
    cout << ans << endl;
    return 0;
}
