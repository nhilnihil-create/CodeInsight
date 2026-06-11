#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define p pair<int,int>
template<class T> void chmax(T& a, T b){if(a < b) a = b;}
template<class T> void chmin(T& a, T b){if(a > b) a = b;}
int N, M;
int num[100010];
int mod[100010];
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int X;
        cin >> X;
        num[X]++;
        mod[X % M]++;
    }
    int ans = 0;
    for(int i = 1; i < (M + 1) / 2; i++){
        int mini = min(mod[i], mod[M - i]); 
        ans += mini;
        mod[i] -= mini;
        mod[M - i] -= mini;
    }

    ans += mod[0] / 2;
    mod[0] %= 2;

    if(M % 2 == 0){
        ans += mod[M / 2] / 2;
        mod[M / 2] %= 2;
    }

    for(int i = 1; i <= 1e5; i++){
        int mini = min(num[i] / 2, mod[i % M] / 2);
        ans += mini;
        mod[i % M] -= mini * 2;
    }

    cout << ans << endl;
    return 0;
}