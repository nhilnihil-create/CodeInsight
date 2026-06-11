#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;

int n;
string s;
bool check(int x,int y,vector<int> &v){
    v.push_back(x);
    v.push_back(y);
    rep(i,n-1){
        if(s[i+1] == 'o'){
            if(v[i+1] == 0)v.push_back(v[i]);
            else v.push_back(v[i]^1);
        }
        else {
            if(v[i+1] == 0)v.push_back(v[i]^1);
            else v.push_back(v[i]);
        }
        
    }
    if(s[0] == 'o'){
        if(x == 0)return (v[1] == v[n-1])&&(v[0] == v[n]);
        else return (v[1] != v[n-1])&&(v[0] == v[n]);
    }
    else{
        if(x == 0)return (v[1] != v[n-1])&&(v[0] == v[n]);
        else return (v[1] == v[n-1])&&(v[0] == v[n]);
    }
    
}

signed main(){
    cin >>n ;
    cin >> s;
    vector<int> v1,v2,v3,v4;
    string ans = "";
    if(check(0,0,v1)){
        rep(i,n){
            if(v1[i] == 0)ans += 'S';
            else ans+= 'W';
        }
        cout << ans  << endl;
        return 0;

    }
    

    if(check(0,1,v2)){
        rep(i,n){
            if(v2[i] == 0)ans+='S';
            else ans+='W';
        }
        cout << ans << endl;
        return 0;

    }
    
    if(check(1,0,v3)){
        rep(i,n){
            if(v3[i] == 0)ans += 'S';
            else ans+= 'W';
        }
        cout << ans << endl;
        return 0;

    }
    
    if(check(1,1,v4)){
        rep(i,n){
            if(v4[i] == 0)ans+= 'S';
            else ans+= 'W';
        }
        cout << ans << endl;
        return 0;

    }
    cout << -1 << endl;


    return 0;
}