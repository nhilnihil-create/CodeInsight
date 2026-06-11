#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    int n;
    cin >> n;
    deque<int> ans;
    rep(i,n){
        int a;
        cin >> a;
        if(i%2 == n%2){
            ans.push_back(a);
        }
        else{
            ans.push_front(a);
        }
    }
    rep(i,n){
        cout << ans[i] <<" ";
    }
    cout << endl;
}