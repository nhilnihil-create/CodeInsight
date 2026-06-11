#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)


int main(){
    string s;
    cin >> s;
    if(s.size() == 2){
        if(s[0] == s[1]){
            cout << 1 << " " << 2 << endl;
            return 0;
        }
    }

    rep(i, 26){
        int num = 0;
        if(s[0] - 'a' == i) num++;
        if(s[1] - 'a' == i) num++;
        for (int j = 2; j < s.size(); j++){
            if(s[j] - 'a' == i) num++;
            if(num >= 2){
                cout << j - 1 << " " << j + 1 << endl;
                return 0;
            }
            if(s[j-2] - 'a' == i) num--;
        }
    }
    cout << -1 << " " << -1 << endl;

}
