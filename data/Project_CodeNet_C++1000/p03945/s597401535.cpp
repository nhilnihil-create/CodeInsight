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
    string S;
    cin >> S;
    
    int cnt=0;
    char c=S[0];
    for(auto &s:S){
        if(c!=s){
            cnt++;
            c=s;
        }
    }
    cout << cnt << endl;
}