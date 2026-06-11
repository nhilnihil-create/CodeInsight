#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,flag,cnt = 0,dist = 0;
    cin >> N;
    vector<int> A(N);

    rep(i, N){
        cin >> A[i];
    }

    rep(i,N-1){
        if(dist == 0){
            if(A[i] < A[i+1]){
                dist = 1;
            }
            if(A[i] > A[i+1]){
                dist = -1;
            }
        }

        else if(dist == 1 && A[i] > A[i+1]){
            dist = 0;
            cnt++;
        }

        else if(dist == -1 && A[i] < A[i+1]){
            dist = 0;
            cnt++;
        }
    }

    cout << cnt+1 << endl;

    return 0;
}