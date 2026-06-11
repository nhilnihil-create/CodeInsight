#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    vector<int> x;
    vector<int> y;
    int xtmp, ytmp;
    for(int ix=0;ix<=30;ix++) {
        for(int jx=0;jx<=30;jx++) {
            xtmp = 100*a*ix+100*b*jx;
            if(xtmp<=f) x.push_back(xtmp);
        }
    }
    for(int iy=0;iy<=3000;iy++) {
        for(int jy=0;jy<=3000;jy++) {
            ytmp = c*iy+d*jy;
            if(ytmp<=f) y.push_back(ytmp);
        }
    }

    int dmaxsum = 1, dmaxsugar = 0;
    int sum = 0, sugar = 0;
    for(std::vector<int>::const_iterator ix = x.begin(), ex = x.end(); ix != ex; ++ix) {
        for(std::vector<int>::const_iterator iy = y.begin(), ey = y.end(); iy != ey; ++iy) {
            if(*ix+*iy==0) continue;
            if((dmaxsugar*(*ix+*iy)<*iy*(dmaxsum))&&((*ix+*iy)<=f)&&(e*(*ix+*iy)>=*iy*(100+e))) {
                dmaxsum = *ix+*iy;
                dmaxsugar = *iy;
            }
        }
    }
    if(dmaxsum==1&&dmaxsugar==0) {
        dmaxsum = 100*a;
        dmaxsugar = 0;
    }
    cout << dmaxsum << " " << dmaxsugar << endl;
    return 0;
}
