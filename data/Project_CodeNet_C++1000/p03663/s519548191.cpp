#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
string zero = "999999999999999999";
int main(){
    string s = "";
    for(ll i = 1;;i++){
        char ret;
        if(i != 1){
            if(s[0] != '1'){
                string t = (char)(s[0] - 1) + s.substr(1) + '0';
                cout << "? " << t << endl << flush;
                cin >> ret;
                if(ret == 'N'){
                    cout << "! " << s << endl;
                    return 0;
                }
            }else{
                string t = s + '0';
                t = '9' + t.substr(2);
                cout << "? " << t << endl << flush;
                cin >> ret;
                if(ret == 'Y'){
                    cout << "! " << s << endl;
                    return 0;
                }
            }
            cout << "? " << s + '0' + zero.substr(0, 18 - s.size() - 1) << endl << flush;
            cin >> ret;
            if(ret == 'Y'){
                s = s + '0';
                continue;
            }
        }
        ll ng = 0, ok = 9;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            cout << "? " << s + (char)(mid + '0') + zero.substr(0, 18 - s.size() - 1) << endl << flush;
            cin >> ret;
            if(ret == 'Y') ok = mid;
            else ng = mid;
        }
        s = s + (char)(ok + '0');
    }
}