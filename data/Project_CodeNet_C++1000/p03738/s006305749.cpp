#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b; cin >> a; cin >> b;

    int res = 0; // a>b : 1   a=b : 0 a<b : -1
    
    if(a.size()>b.size())
        res = 1;
    if(a.size()<b.size())
        res = -1;
    if(a.size() == b.size()){
        for(int i=0; i<a.size(); i++){
            if(a.at(i)>b.at(i)){
                res = 1; break;
            }else if(a.at(i) < b.at(i)){
                res = -1; break;
            }
        }
    }
        
    if(res == 1)
        cout << "GREATER" << endl;
    else if(res == -1)
        cout << "LESS" << endl;
    else if(res == 0)
        cout << "EQUAL" << endl;

    return 0;
}