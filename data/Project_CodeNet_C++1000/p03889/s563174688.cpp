#include <iostream>
#include <string>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;


int main(){
    string s;cin>>s;
    int len = s.size();
    bool flag = true;
    if(len % 2 == 0){
        for(int i=0; i<len/2; i++){
            if(s[i] == 'p' && s[len-1-i] != 'q') flag = false;
            else if (s[i] == 'q' && s[len-1-i] != 'p') flag = false;
            else if (s[i] == 'b' && s[len-1-i] != 'd') flag = false;
            else if (s[i] == 'd' && s[len-1-i] != 'b') flag = false;
        }
    }else{
        flag = false;
    }

    string ans = flag ? "Yes" : "No";
    cout << ans << endl;
    return 0;
}