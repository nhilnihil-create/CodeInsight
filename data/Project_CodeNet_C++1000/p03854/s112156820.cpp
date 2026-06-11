#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int index = 0;
    int N = S.size();
    string S1 = "dream";
    string S2 = "dreamer";
    string S3 = "erase";
    string S4 = "eraser";
    while(N>index){
        if(S.substr(N-S1.size()-index,S1.size()) == S1)index += 5;
        else if(S.substr(N-S3.size()-index,S3.size()) == S3)index += 5;
        else if(S.substr(N-S4.size()-index,S4.size()) == S4)index += 6;
        else if(S.substr(N-S2.size()-index,S2.size()) == S2)index += 7;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
