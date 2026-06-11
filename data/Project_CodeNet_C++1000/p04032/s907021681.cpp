#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n=s.length();
    int i=0;
    int check=0;

    while(1){
        if(s[i]==s[i+1]){
            check=1;
            break;
        }
        if(s[i]==s[i+2]){
            check=2;
            break;
        }
        i++;
        if(i==n) break;
    }

    if(check==0){
        cout << -1 << ' ' << -1 << endl;
    }
    else if(check==1){
        cout << i+1 << ' ' << i+2 << endl;
    }
    else{
        cout << i+1 << ' ' << i+3 << endl;
    }

    return 0;
}