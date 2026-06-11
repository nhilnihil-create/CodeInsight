#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool check=false;
    int num=s.length();
    //cout << num << endl;
    
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            if(s.at(i)==s.at(j)){
                check=true;
            }
        }
    }
    if(check) cout << "no" << endl;
    else cout << "yes" << endl;
}