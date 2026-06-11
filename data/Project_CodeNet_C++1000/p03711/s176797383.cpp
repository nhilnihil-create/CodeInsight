#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int check(int x){
    if(x == 4 || x == 6 || x == 9 || x == 11) return 1;
    else if (x == 2) return 2;
    else return 0;
}

int main(){
    int x, y; cin >> x >> y;
    int a = check(x);
    int b = check(y);
    if(a == b) cout << "Yes" << endl;
    else cout << "No" << endl;
}