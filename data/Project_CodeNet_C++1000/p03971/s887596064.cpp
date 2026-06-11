#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int abc = 0;
    int clas=0;
    for(int i=0; i<n; i++){
        if(s[i]=='b'){
            abc++;
            if(clas <= a+b-1 && abc <= b){
                clas++;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(s[i]=='a'){
            if(clas <= a+b-1){
                clas++;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
}


