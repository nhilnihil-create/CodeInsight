#include <bits/stdc++.h>
using namespace std;
int main(){
    string o="",e="";
    cin >> o >> e;
    
    int all = o.size();
    
    for(int i=0;i < o.size();i++){
        cout << o[i];
        if(i < e.size())cout << e[i];
    }
    
    return 0;
}
