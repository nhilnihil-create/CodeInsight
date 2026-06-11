#include<bits/stdc++.h>
using namespace std;
int main(){
    string o,e;
    cin >> o >> e;
    int sz;
    sz = o.size() + e.size();
    int cno,cne;
    cno=0;
    cne=0;
    for(int i=0; i<sz; i++){
        if(i%2==0){
            cout << o[cne];
            cne++;
        }else{
            cout << e[cno];
            cno++;
        }
    }
    cout << endl;
}


