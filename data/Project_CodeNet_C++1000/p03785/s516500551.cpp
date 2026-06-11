#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    int N, C, K;
    cin >> N >> C >> K;

    vector<int>t(N);
    rep(i,N)cin >> t[i];


    sort(t.begin(),t.end());

    int bus =0;
    for(int i=0; i <N ;){
        bus += 1;
        int start =i;
        while(i < N && t[i]-t[start] <= K && i-start < C ){
            i +=1;
        }
    }

    cout << bus  << endl;
    
}

