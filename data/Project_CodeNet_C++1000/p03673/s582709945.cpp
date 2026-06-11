#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    deque<int> q;
    rep(i,n) {
        int a;
        cin >> a;
        if(i%2==0) q.push_back(a);
        else q.push_front(a);
    }
    if(n&1){
        while(!q.empty()){
            cout << q.back() << " ";
            q.pop_back();
        }
    }
    else {
         while(!q.empty()){
            cout << q.front() << " ";
            q.pop_front();
            
        }
    }
    cout << endl;
    return 0;
}