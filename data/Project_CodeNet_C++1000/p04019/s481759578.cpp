#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    bool flag1=true;
    bool flag2=true;
    bool flag3=true;
    bool flag4=true;
    rep(i,s.size()){
        if(s.at(i)=='N')flag1=false;
        if(s.at(i)=='W')flag2=false;
        if(s.at(i)=='S')flag3=false;
        if(s.at(i)=='E')flag4=false;
    }
    if(!flag1&&!flag3){
        flag1=true;
        flag3=true;
    }
    if(!flag2&&!flag4){
        flag2=true;
        flag4=true;
    }
    if(flag1&&flag2&&flag3&&flag4) cout << "Yes" << endl;
    else cout << "No" << endl;
}
   
