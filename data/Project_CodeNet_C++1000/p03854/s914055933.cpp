#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i = s.size();
    bool tag = true;
    while (i != 0)
    {
        if(i > 4 && s.substr(i-5,5) == "dream"){
            i -= 5;
        }
        else if(i > 6 && s.substr(i-7,7) == "dreamer"){
            i -= 7;
        }
        else if(i > 4 && s.substr(i-5,5) == "erase"){
            i -= 5;
        }
        else if(i > 5 && s.substr(i - 6, 6) == "eraser"){
            i -= 6;
        }
        else{
            tag = false;
            break;
        }


    }
    if(tag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
