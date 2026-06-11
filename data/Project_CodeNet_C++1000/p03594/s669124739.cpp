/*
 ***
 Question Name:
 ***
 Question Link:
 ***
 Idea:
 */

#include <memory.h>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define REP(i,s,n) for(int (i)=s; (i)<(int)(n);(i)++)
#define RIT(it,c) for(__typeof(c.begin()) it = c.begin();it!=c.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)(x).size()
#define MSET(m,v) memset(m,v,sizeof(m))

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<LL> vL;
typedef vector<bool> vb;
typedef unordered_set<int> ui;
typedef pair<LL,LL> pLL;

class FourColoring{
    vector<string> Templ= {"RY","BG"};
public:
    void solve(int H,int M, int d){
        for(int i=0;i<H;++i){
            for(int j=0;j<M;++j) cout<<Templ[((i+j+H+M)/d)%2][((i-j+H+M)/d)%2];
            cout<<endl;
        }
    }
};

int main(){
    int H,M,d;
    cin>>H>>M>>d;
    FourColoring().solve(H, M, d);
    return 0;
}