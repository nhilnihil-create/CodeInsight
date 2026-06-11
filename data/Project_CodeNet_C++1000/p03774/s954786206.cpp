#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N,M;
    cin >> N >> M;
    //
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(M);
    vector<int> d(M);
    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i] ;
    }
    for(int i=0;i<M;i++){
        cin >> c[i] >> d[i] ;
    }
    //
    for(int i=0;i<N;i++){
        ll dist;
        ll min_dist;
        int min_point;
        for(int j=0;j<M;j++){
            dist = abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(j==0){
                min_dist = dist;
                min_point = j;
            }
            else{
                if(min_dist > dist){
                    min_dist = dist;
                    min_point = j;
                }
            }
        }
        cout << min_point+1 << endl;
    }
}