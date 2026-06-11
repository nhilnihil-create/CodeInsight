#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int N;
vector<int> A;
map<int, int> X;

bool solve(int room){
    int rem = N - room;
    int least = 0;
    if(rem == 0){
        if(X[room-1] == N) return true;
        else return false;
    }

    if(rem < room) least = room - rem;
    for(int i = least; i < room; i++){
        if(X[room-1] == i && X[room] == N-i){
            return true;
        }
    }
    return false;
}

int main(){
    int large = 0;
    cin >> N;
    REP(i,N){
        int a;
        cin >> a;
        //A.push_back(a);
        chmax(large, a);
        X[a]++;
    }

    //sort(A.rbegin(), A.rend());

    //int first = A[0];

    bool valid = solve(large);
    if(valid) goto success;

    valid = solve(large+1);
    if(valid) goto success;

    cout << "No" << endl;
    return 0;

success:
    cout << "Yes" << endl;

    return 0;
}
