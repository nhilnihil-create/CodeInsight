#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int l = s.size();
    while(l > 0){
        if(l >= 5 && s.substr(l - 5, 5) == "dream"){
            l = l - 5;
        }
        else if(l >= 7 && s.substr(l - 7, 7) == "dreamer"){
            l = l - 7;
        }
        else if(l >= 5 && s.substr(l - 5, 5) == "erase"){
            l = l - 5;
        }
        else if(l >= 6 && s.substr(l - 6, 6) == "eraser"){
            l = l - 6;
        }
        else break;
    }
    if(l == 0) puts("YES");
    else puts("NO");
}