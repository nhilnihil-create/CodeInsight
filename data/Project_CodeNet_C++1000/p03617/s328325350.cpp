#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    ll q,h,s,d,n;
    cin >> q >> h >> s >> d;
    cin >> n;
    q *= 4;h *= 2;
    s = min(q,s);s = min(h,s);
    if (2*s <= d){
        cout << n*s;
    }
    else{
        cout << d*(n/2) + s*(n%2);
    }
}