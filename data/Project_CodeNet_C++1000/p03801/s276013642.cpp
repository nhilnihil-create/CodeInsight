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

int N,M,K,C[maxN];
LL A[maxN],res[maxN];

bool cmp(int i,int j){
    return A[i] == A[j] ? i < j : A[i] > A[j];
}
void testcase(){
    scanf("%d",&N);
    FOR(i,1,N){
        scanf("%lli",&A[i]);
        C[i] = i;
    }
    sort(C + 1,C + 1 + N,cmp);
    //
    int first = 1;
    int curpos = C[1];

    while(first <= N){
        int last = first;
        while(last < N && A[C[last + 1]] == A[C[last]]) ++last;
        if(last >= N){
            res[curpos] += A[C[first]] * last;
            break;
        }else res[curpos] += (A[C[first]] - A[C[last + 1]]) * last;
        //
        first = last + 1;
        curpos = min(curpos,C[first]);
    }
    FOR(i,1,N) printf("%lli\n",res[i]);
}

int main(){

    //cin >> tcases;

    FOR(i,1,tcases) testcase();

    return 0;
}