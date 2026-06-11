#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)



int main(){
    string a,b;
    cin >> a >> b;
    bool e = true;
    if(a.size()>b.size()){
        cout << "GREATER" << endl;
        e = false;
    }else if(a.size()<b.size()){
        cout << "LESS" << endl;
        e = false;
    }else{
        for(int i=0;i<a.size();i++){
            if(a.at(i)>b.at(i)){
                cout << "GREATER" << endl;
                e = false;
                break;
            }else if(a.at(i)<b.at(i)){
                cout << "LESS" << endl;
                e = false;
                break;
            }else if(a.at(i)==b.at(i)){
                continue;
            }
        }
    }
    if(e) cout << "EQUAL" << endl;
}
    