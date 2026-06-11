#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N; cin >> N;
    string S; cin >> S;
    string ans = "";
    int left_count = 0;
    for (int i = 0; i < N ; i++){
        if (S[i] == '('){
            left_count++;
        }
        else{
            if (left_count > 0){
                left_count--;
            }
        }
    }
    int right_count = 0;
    for (int i = N-1; i >= 0; i--){
        if (S[i] == ')'){
            right_count++;
        }
        else{
            if (right_count > 0){
                right_count--;
            }
        }
    }
    if (right_count > 0){
        rep(i,right_count){
            ans += '(';
        }
    }
    ans += S;
    if (left_count > 0){
        rep(i, left_count){
            ans += ')';
        }
    }

    cout << ans << endl;
}