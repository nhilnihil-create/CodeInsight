#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    int n;
    cin >> n;

    vector<int> ans(9,0);
    int ans_max = 0, ans_min = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if((1<=a) && (a<=399)) ans[0]++;
        else if((400<=a) && (a<=799)) ans[1]++;
        else if((800<=a) && (a<=1199)) ans[2]++;
        else if((1200<=a) && (a<=1599)) ans[3]++;
        else if((1600<=a) && (a<=1999)) ans[4]++;
        else if((2000<=a) && (a<=2399)) ans[5]++;
        else if((2400<=a) && (a<=2799)) ans[6]++;
        else if((2800<=a) && (a<=3199)) ans[7]++;
        else ans[8]++;
    }

    for(int i = 0; i < 9; i++){
        if(i == 8){
            ans_max += ans[8];
            if(ans_min == 0) ans_min = 1; 
        }
        else{
            if(ans[i] != 0){
                ans_max++;
                ans_min++;
            }
        }
    }
    cout << ans_min << " " << ans_max << endl;

    return 0;
}
