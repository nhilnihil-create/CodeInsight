#include <bits/stdc++.h>
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
#define MOD 1000000007
using ll = long long;
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n, m;
cin >> n >> m;
vector<int> box(n,1);
vector<bool> prob(n,false);
prob[0] = true;
int x, y;

rep(i, m){
     cin >> x >> y;
     x--, y--;
    if(prob[x]){
        prob[y]=true;
    }
    box[x]--;
    box[y]++;
    if(box[x]==0){
        prob[x] = false;
    }
}
int sum = 0;
for(auto v:prob){
    if(v){
        sum++;
    }
}
cout << sum << endl;
//system("pause");
return 0;
}