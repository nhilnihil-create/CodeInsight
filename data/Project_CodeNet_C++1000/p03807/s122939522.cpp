#include<iostream>
using namespace std;
 #define REP(i, N) for(int i = 0; i < N; i++)
 
int main() {
    int N, a[100000];
    cin >> N;
    REP(i, N) cin >> a[i];
 
    int oddNum = 0;
    REP(i, N) {
        if(a[i]%2 == 1) oddNum++;
    }
    cout << (oddNum % 2 == 0? "YES": "NO") << endl;
}