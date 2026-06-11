#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    set<int> s;
    int count = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a >= 3200) count++;
        else{
            s.insert(a/400);
        }
    }
    if(s.size() == 0){
        cout << 1;
    }
    else{
        cout << s.size();
    }
    cout << " " << s.size() + count << endl;
}