#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int a=0,b=0,c=0,d=0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'N') a++;
        else if(s[i] == 'S') b++;
        else if(s[i] == 'W') c++;
        else if(s[i] == 'E') d++;
    }
    if((a == 0 && b >= 1) || (b == 0 && a >= 1) || (c == 0 && d >= 1) || (d == 0 && c >= 1)){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    //cout << a << " " << b <<  " " << c <<  " " << d << endl;
    return 0;
}
