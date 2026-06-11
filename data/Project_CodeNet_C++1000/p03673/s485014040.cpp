#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int n;
    cin>>n;
    vector<int> a;
    rep(i,n){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    vector<int> ans;
    //ansに詰める順番はaの最後尾から一個飛ばしで先頭まで集める⇒先頭まで来たら折り返して末尾の一個前まであつｍる
    for(int i=n-1;i>=0;i=i-2){
        ans.push_back(a[i]);
    }
    //nが偶数なら折り返しは先頭の要素から,奇数なら2個目から
    for(int i=n%2;i<n;i=i+2){
        ans.push_back(a[i]);
    }

    //出力
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}