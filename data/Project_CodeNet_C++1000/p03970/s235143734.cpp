#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    string target = "CODEFESTIVAL2016";

    int acc = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] != target[i]){
            acc++;
        }
    }
    cout << acc <<endl;
    return 0;
}