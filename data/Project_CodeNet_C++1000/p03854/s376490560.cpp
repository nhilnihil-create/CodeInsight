#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>

using namespace std;

int main()
{
    string S, T;    cin >> S;
    int i, l;
    i = 0;
    l = S.size();
    S += "zzzzzzzzzz";
    while(i < l-1){
        if(S.substr(i,6) == "eraser"){
            i += 6;
        }else if(S.substr(i,5) == "erase"){
            i += 5;
        }else if(S.substr(i,8) == "dreamerd" || S.substr(i,8) == "dreamere"){
            i += 7;
        }else if(i == l-7 && S.substr(i,7) == "dreamer"){
            i += 7;
        }else if(S.substr(i,5) == "dream"){
            i += 5;
        }else{
            cout << "NO";
            return 0;
        }
        if(i > l-5 && i < l-1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}