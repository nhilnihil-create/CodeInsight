
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)



int main() {
    int h, w;
    cin >> h >> w;
    char buf[256];
    string snuke = "snuke";
    REP(j, h) REP(i , w) {
        cin >> buf;
        if (snuke == buf) {
            char col = 'A' + i;
            int row = 1 + j;
            cout << col << row << endl;
            return 0;
        }
    }
    return 0;
}
