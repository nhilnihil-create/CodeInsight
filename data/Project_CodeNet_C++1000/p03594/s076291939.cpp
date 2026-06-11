#include <iostream>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)

int main(void) {
    int i, j, h, w, d;
    cin >> h >> w >> d;
    REP (i,h) {
        REP (j,w) printf("%c","RYGB"[(i+j)/d%2+(i-j+500*d)/d%2*2]);
        puts("");
    }
    return 0;
}