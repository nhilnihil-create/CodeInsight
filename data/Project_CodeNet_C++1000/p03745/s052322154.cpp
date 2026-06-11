#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    int N;
    cin >> N;

    vector<int>A(N);
    rep(i,N)cin >> A[i];

    int ans=1;
    for(int i =0; i<N-1;){
        //差が0ならスルー
        if(A[i+1]-A[i] ==0){
        i +=1;
        continue;
        }

        //増加
        if(A[i+1]-A[i] >0){
            repr(j,i,N-1){
                i=j+1;
                if(A[j+1]-A[j] < 0){
                    ans+=1;
                    break;
                }
            }
        }

        //減少
        if(A[i+1]-A[i] < 0){
            repr(j,i,N-1){
                i=j+1;
                if(A[j+1]-A[j] > 0){
                    ans+=1;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

