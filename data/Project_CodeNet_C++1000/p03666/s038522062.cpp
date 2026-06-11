#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    long N, A, B, C, D;
    cin>>N >> A >> B >> C >> D;
    string ans = "NO";
    REP(i, 0, N){
        long j = N-1-i;
        long min_R = -D*j + C*i;
        long max_R = -C*j + D*i;
        if(min_R <= B-A && B-A <= max_R) ans = "YES";
    }
    cout << ans << endl;
}