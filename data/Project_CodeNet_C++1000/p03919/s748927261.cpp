#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string s[a][b];
    for(int i = 0;i < a;i++){
        for(int j = 0;j < b;j++){
            cin >> s[i][j];
            if(s[i][j] == "snuke"){
                cout << (char)(j + 'A') << i+1 << endl;
            }
        }
    }
    
}