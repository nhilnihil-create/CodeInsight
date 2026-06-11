#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll H,W;
    cin >> H >> W;
    vector<vector<char>> A(H,vector<char>(W));
    map<char,ll> mp;
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
            mp[A[i][j]]++;
        }
    }
    ll cnt4 = 0;
    ll cnt2 = 0;
    ll cnto = 0;
    for(auto& p:mp){
        if(p.second >= 4){
            cnt4 += p.second/4;
            p.second %= 4;
        }
        if(p.second >= 2){
            cnt2 += p.second / 2;
            p.second %= 2;
        }
        if(p.second % 2 == 1){
            cnto++;
        }
    }
    ll four = (H/2) * (W/2);
    ll two = H*(W%2) + W*(H%2);// - (H%2) - (W%2);
    ll odd;
    if(H%2 && W%2)odd = 1;else odd = 0;
    two -= odd;
    two /= 2;

    //cout << cnt4 <<" "<<cnt2 <<" "<< cnto <<endl;
    //cout << four <<" "<<two <<" "<< odd <<endl;

    if(cnt4 >= four){
        cnt2 += (cnt4 - four)*2;
        if(cnt2 >= two){
            cout << "Yes"<<endl;
            return 0;
        }
    }
    cout << "No" << endl;
/*
    if(cnt <= min(H,W)){
        cout << "Yes" << endl;
    }else{
    }
*/
}
