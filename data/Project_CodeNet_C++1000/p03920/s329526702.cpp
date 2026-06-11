
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)


const int NMAX = 10000005;

int isOKsMemo[NMAX];
const int NOT_CHECK = 0;
const int OK = 1;
const int NO = -1;

int n;

int isOK(int maxValue){
    if (isOKsMemo[maxValue] != NOT_CHECK) return isOKsMemo[maxValue];
    
    int v = n;
    int s = maxValue;
    while(v > 0){
        if(s == 0){
            return isOKsMemo[maxValue] = NO;
        }
        if (v <= s){
            v = 0;
            s = 0;
        }
        else {
            v -= s;
            s--;
        }
    }
    return isOKsMemo[maxValue] = OK;
}
void printValues(int maxValue){
    int v = n;
    int s = maxValue;
    while(v > 0){
        if (v <= s){
            cout << v << endl;
            v = 0;
        }
        else {
            cout << s << endl;
            v -= s;
            s--;
        }
    }
}

int main() {
    cin >> n;
    int l = 0;
    int r = n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if (isOK(mid) == OK){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    printValues(r);
    
    return 0;
}
