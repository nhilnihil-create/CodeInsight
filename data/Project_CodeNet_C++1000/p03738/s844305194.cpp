#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    if(a.length()>b.length()){
        cout << "GREATER" << endl;
    }else if(a.length()<b.length()){
        cout << "LESS" << endl;
    }else{
        for(int i = 0; i < a.length(); i++){
            if(a[i]>b[i]){
                cout << "GREATER" << endl;
                break;
            }else if(a[i]<b[i]){
                cout << "LESS" << endl;
                break;
            }else{
                if(i == a.length()-1){
                    cout << "EQUAL" << endl;
                }
            }
        }
    }
    return 0;
}