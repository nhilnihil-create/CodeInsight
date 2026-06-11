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
    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N){
        int a;cin >> a;
        p[--a]=i;
    }
    vector<int> a(N),b(N);
    int M = 30000;
    rep(i,N){
        a[i]=M*i+1+p[i];
        b[i]=M*(N-i)+1;
    }

    rep(i,N)cout << a[i] <<" ";
    cout << endl;
    rep(i,N)cout << b[i] <<" ";
    cout << endl;
    return 0;
}