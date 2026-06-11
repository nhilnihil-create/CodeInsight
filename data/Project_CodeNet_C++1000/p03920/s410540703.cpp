#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;

int N;
ll sum;
int main(){
    cin>>N;
    int mx=1;
    REP(i,1,N+1) {
        sum += i;
        if (sum > N) {
            mx=i;
            break;
        }
    }
    REP(i,1,mx+1){
        if(sum-i!=N){
            p(i);
        }
    }
    return 0;
}