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

typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<int,int> ii;
typedef pair<long, long> ll;
typedef unordered_set<int> ui;

class IntegerotS{
    unordered_map<int, long> cnt;
    int K;
    void init(){
        int N;
        cin>>N>>K;
        for(int i=0;i<N;++i){
            int a,b;
            cin>>a>>b;
            if(a<=K) cnt[a] += (long)b;
        }
    }
    long pass(int nk){
        long ans = 0;
        for(auto p:cnt) if(!(p.first & nk)) ans += p.second;
        return ans;
    }
public:
    long solve(){
        init();
        int NK = (-1)^K;
        long ans = pass(NK);
        for(int j=0;j<32;++j){
            if(((NK>>j)&1) == 0){
                NK |= (1<<j);
                ans = max(ans, pass(NK));
            }
            NK &= NK-1;
        }
        return ans;
    }
};

int main(){
    std::ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cout<<IntegerotS().solve()<<endl;
    return 0;
}