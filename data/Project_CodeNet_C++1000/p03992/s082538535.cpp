#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
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
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        cout<<s.at(i);
        if(i==3){
            cout<<" ";
        }
    }
    cout<<endl;





    return 0;
}
