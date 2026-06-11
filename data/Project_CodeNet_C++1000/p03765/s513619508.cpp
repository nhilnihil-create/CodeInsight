#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <math.h>
#include <bitset>

using namespace std;

#define taskname "A"
#define LL long long 
#define uLL unsigned long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,l,r) for(int i = l; i < r; ++i)
#define FORD(i,r,l) for(int i = r; i >= l; --i)
#define REPD(i,r,l) for(int i = r; i > l; --i)
#define pi pair<int,int>
#define pii pair<int,pi>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define _USE_MATH_DEFINES 
/* M_PI */

const int maxN = 2e5 + 11;
const LL oo = 1e17 + 11;

int tcases = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char ch;
int readInt(){
    bool fl = 0;
    while(ch = getchar(),ch != '-' && (ch < '0' || ch > '9'));
    if(ch == '-'){
        fl = 1;
        while(ch = getchar(),ch < '0' || ch > '9');
    }
    int r = ch - '0';
    while(ch = getchar(),ch >= '0' && ch <= '9') r = r * 10 + (ch - '0');
    return fl ? -r : r;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int M;
string S,T;
int A[maxN][2],B[maxN][2];

void testcase(){
    cin >> S >> T;
    FOR(i,1,S.size()){
        A[i][0] = A[i - 1][0] + (S[i - 1] == 'A');
        B[i][0] = B[i - 1][0] + (S[i - 1] == 'B');
    }
    FOR(i,1,T.size()){
        A[i][1] = A[i - 1][1] + (T[i - 1] == 'A');
        B[i][1] = B[i - 1][1] + (T[i - 1] == 'B');
    }
    cin >> M;
    FOR(i,1,M){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int c1 = ((A[r1][0] - A[l1 - 1][0]) * 2 + (B[r1][0] - B[l1 - 1][0]));
        int c2 = ((A[r2][1] - A[l2 - 1][1]) * 2 + (B[r2][1] - B[l2 - 1][1]));
        if((c1 - c2) % 3 == 0){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //

    //cin >> tcases;

    FOR(i,1,tcases) testcase();

    return 0;
}