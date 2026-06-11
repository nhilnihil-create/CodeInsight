#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;

main(){
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    string div[4] = {"maerd","remaerd","esare","resare"};

    bool can = true;
    for (int i =0; i < s.size();){
        bool can2 = false;
        for (int j = 0;j < 4;j++){
            string d = div[j];
            if (s.substr(i,d.size()) == d){
                can2 = true;
                i += d.size();
            }
        }
        if (!can2){
            can = false;
            break;
        }
    }

    if (can){
       cout << "YES" << endl;
    } else {
       cout << "NO" << endl;
    }  
  
    return 0;
} 