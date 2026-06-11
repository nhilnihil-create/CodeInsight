#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int N;  cin >> N;
    ll cnt = 0;
    vector<ll> A(N), B(N);
    for(int i=0; i<N; i++)  cin >> A[i] >> B[i];
    for(int i=N-1; i>=0; i--){
        if((A[i] + cnt) % B[i] != 0){
            cnt += ((A[i] + cnt) / B[i] + 1) * B[i] - A[i] - cnt;
        }
    }
    cout << cnt;
}