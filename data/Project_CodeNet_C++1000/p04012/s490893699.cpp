#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string w;
    cin >> w;
    sort(w.begin(),w.end());
    bool flag=true;
    if(w.size()%2==1){
        cout << "No" << endl;
    }
    else{
        for(int i=0;i<w.size();i+=2){
            if(w.at(i)!=w.at(i+1))flag=false;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
