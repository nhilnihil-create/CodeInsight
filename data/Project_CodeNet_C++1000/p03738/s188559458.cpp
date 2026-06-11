#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int sa,sb;
    sa = a.size();
    sb = b.size();
    if(sa>sb){
        cout << "GREATER" << endl;
        return 0;
    }else if(sa <sb){
        cout << "LESS" << endl;
        return 0;
    }else if(sa == sb){
        for(int i=0; i<sa; i++){
            if(a[i] < b[i]){
                cout << "LESS" << endl;
                return 0;
            }else if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
}


