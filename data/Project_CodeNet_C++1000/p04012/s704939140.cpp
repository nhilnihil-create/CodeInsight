#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    bool check = true;
    for(int i=0; i < w.size(); i++){
        if(count(w.begin(), w.end(), w.at(i)) % 2 != 0){
            check = false;
            break;
        }
    }

    if(check){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}