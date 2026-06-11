#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int max_len = 0;
    int a_ids =0, z_ids =0;
    bool flg = false;
    for(int i=0; i<s.length();i++){
        if(s.at(i)=='A' && flg==false){
            flg = true; a_ids = i;
        }
        if(s.at(i) == 'Z'){
            z_ids =i;
        }
    }
    max_len = z_ids - a_ids + 1;

    cout << max_len << endl;
    return 0;
}