#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

#define MOD 1000000007


int main(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll res = 1;
    bool pre;
    rep(i, n){
        if(s1[i] == s2[i]){
            if(i == 0)res*=3;
            else if(pre)res=(res*2)%MOD;
            pre = true;
        }
        else{
            if(i == 0)res*=6;
            else if(pre)res=(res*2)%MOD;
            else res=(res*3)%MOD;
            pre = false;
            i++;
        }
    }
    cout << res << endl;
}
