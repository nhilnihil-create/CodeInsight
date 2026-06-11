
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string s;
    cin >> s;
    //最低一回は末尾を消す必要がある
    s.pop_back();

    int length,size;
    length = s.size();
    size = s.size();
    rep(i, size){
        if((length % 2 == 0) && (s.substr(0,length/2) == s.substr(length/2, length/2))){
            cout << length << endl;
            return 0;
        }
        else{
            s.pop_back();
            length = s.size();
        }
    }
}
        
    
    
