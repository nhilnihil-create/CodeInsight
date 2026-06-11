#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long n;
    string s, t;
    cin >> n >> s >> t;
    long pos = s.length();
    for(int i = 0; i < s.length(); i++){
        string u = s.substr(i), v = t.substr(0, u.length());
        if(u == v){
            pos = i;
            break;
        }
    }
    cout << pos + t.length() << endl;
    return 0;
}