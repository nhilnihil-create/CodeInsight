#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string s;
    cin >> s;
    if(s[0]==*(s.end()-1)){
        if((int)s.size()%2==1){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }else{
        if((int)s.size()%2==1){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
}