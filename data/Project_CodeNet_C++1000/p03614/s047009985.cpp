#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

int main(){
    int N;cin >> N;
    vector<int> p(N);
    rep(i,N)cin >> p[i];
    int res = 0;
    for(int i=0;i<N;i++){
        if(p[i]==i+1){
            swap(p[i],p[i+1]);
            res++;
        }            
    }
    cout << res << endl;
    return 0;
}