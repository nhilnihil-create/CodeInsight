#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

#define rep(i, s) for (int i = 0; i < s; ++i)
#define all(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define VEC(a, n) vector<int>a(n)
#define PQ(a) priority_queue<int>a
#define PQmin(a) priority_queue< int, :vector<int>, greater<int> >a
#define PAIR pair<int, int>
/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    int n;
    cin>>n;
    int MAX=0;
    for(int i=0;i<=n;i++){
        if((i*(i+1))/2>=n){
            MAX=i;
            break;
        }
    }
    vector<int>vec;
    for(int i=MAX;i>=1;i--){
        if(n-i>=0){
            n-=i;
            cout<<i<<endl;
        }
    }
    // cout<<"AAA"<<MAX<<endl;



    return 0;
}
