#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> student;
    vector<pair<ll,ll>> check;
    vector<int> ans;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        student.push_back(make_pair(a,b));
    }
    rep(i,m){
        ll a,b;
        cin >>  a >> b;
        check.push_back(make_pair(a,b));
    }
    
    rep(i,n){
        ll  point=3000000000;
        int p;
        rep(j,m){
           ll manha = abs(student[i].first-check[j].first) + abs(student[i].second-check[j].second);
           if(manha<point){
               point = manha;
               p = j+1;
           }
        }
        ans.push_back(p);
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}