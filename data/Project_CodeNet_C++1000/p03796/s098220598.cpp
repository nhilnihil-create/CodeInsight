#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 1; i < (int)(n+1); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}
void print(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << endl;}

int main(){
    int n;
    cin >> n;
    ll power = 1;
    const int c = 1000000007;//10^9
    rep(i,n){
        power = (power*i)%c;
    }
    cout << power;
}