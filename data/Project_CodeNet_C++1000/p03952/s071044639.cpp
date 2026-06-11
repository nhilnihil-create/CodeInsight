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
    int n,x;cin >> n >> x;
    if(x==1||x==2*n-1) cout << "No" << endl;
    else{
        vector<int> a(2*n-1);
        iota(a.begin(),a.end(),1);
        swap(a[n-1],a[x-1]);
        if(a[n-1]<a[n-2]&&a[n-1]<a[n]) swap(a[0],a[n-2]);
		else if(a[n-1]>a[n-2]&&a[n-1]>a[n]) swap(a[n],a[2*n-2]);
        cout << "Yes" << endl;
        for(auto &i:a) cout << i << endl;
    }
}