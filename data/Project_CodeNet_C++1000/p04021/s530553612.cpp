#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    rep(i,N){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(),B.end());
    map<int,int> odd,even;
    rep(i,N){
        if(i%2==0){
            even[B[i]]++;
        }else{
            odd[B[i]]++;
        }
    }
    ll cnt = 0;
    rep(i,N){
        // cout << "i:" << i << " A[i]:" << A[i] << " odd:" << odd[A[i]] << " even:" << even[A[i]] << endl;
        if(i%2==0&&even[A[i]]!=0){
            cnt++;
            even[A[i]]--;
        }else if(i%2==1&&odd[A[i]]!=0){
            cnt++;
            odd[A[i]]--;
        }
    }
    cout << (N - cnt)/2 << endl;
    return 0;
}