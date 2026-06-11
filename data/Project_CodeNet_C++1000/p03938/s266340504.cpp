#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
#define INF 999999999
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;

int main(){
    int n;cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n){
        a[i]=(i+1)*n;
        b[i]=(n-i)*n;
    }
    rep(i,n){
        int data;cin >> data;
        a[data-1]+=i;
    }
    for(auto &i:a) cout << i << " ";
    cout << endl;
    for(auto &i:b) cout << i << " ";
    cout << endl;

}