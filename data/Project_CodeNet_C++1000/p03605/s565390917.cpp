#include<bits/stdc++.h>
using namespace std;
int main(){
    char c[2];
    for(int i=0;i<2;i++){
        cin >> c[i];
        if(c[i]=='9'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}