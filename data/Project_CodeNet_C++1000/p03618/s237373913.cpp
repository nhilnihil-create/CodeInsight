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
    string A; 
    cin>>A;
    vl alph(26, 0);
    long all = A.size() * (A.size()- 1) / 2;
    REP(i, 0, A.size()){
        alph[A[i] - 'a']++;
    }
    long ans = all;
    REP(i, 0, 26){
        ans -= alph[i] * (alph[i] - 1) /2;
    }
    ans++;
    cout << ans << endl;
}