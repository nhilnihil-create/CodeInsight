#include <iostream>
#include <string>
using namespace std;

string O,E;

int main(){
    cin >> O >> E;

    int o = 0;
    int e = 0;
    string ans;
    for(int i = 0;i < O.length() + E.length();i++){
        if(i % 2 == 0){
            ans += O[o];
            o++;
        }else{
            ans += E[e];
            e++;
        }
    }

    cout << ans << endl;
}