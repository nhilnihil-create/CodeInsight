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
    int A,B;cin >> A >> B;
    vector<int> h(N);
    rep(i,N)cin >> h[i];

    auto check = [&](ll k){
        ll res = 0;
        rep(i,N){
            if(h[i]-k*B>0){
                res+=((h[i]-k*B)+(A-B)-1)/(A-B);
            }
        }
        if(res<=k)return true;
        else return false;
    };

    int left=0,right=1<<30;
    while(right>left){
        int mid = (left+right)/2;
        if(check(mid))right=mid;
        else left=mid+1;
    }

    cout << left << endl;
    return 0;
}