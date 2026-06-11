#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() { 
    string o,e;
    cin >> o >> e;
    if(o.size()-e.size()==0){
        rep(i,o.size()){
            cout << o.at(i) << e.at(i);
        }
        cout << endl;
    }
    else{
        rep(i,e.size()){
            cout << o.at(i) << e.at(i);
        }
        cout << o.at(e.size()) << endl;
    }
}
