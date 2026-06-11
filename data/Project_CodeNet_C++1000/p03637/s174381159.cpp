#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    int sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a%2==0) sum++;
        if(a%4==0) sum++;
    }
    if(n%2==1) n--;
    if(n <=sum) cout << "Yes" << endl;
    else cout << "No" << endl;
}