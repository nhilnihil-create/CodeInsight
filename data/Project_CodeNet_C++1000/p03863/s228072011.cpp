#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    if(s.size() % 2 == 0){
        if(s.front() == s.back()){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }else{
        if(s.front() == s.back()){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }
    return 0;
}
