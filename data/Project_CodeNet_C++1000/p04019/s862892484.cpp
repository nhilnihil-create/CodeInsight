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
using namespace std;

const double PI=acos(-1);

int main(){
    string s;
    int d[4] = {0};
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'N') d[0]++;
        else if(s[i] == 'S') d[1]++;
        else if(s[i] == 'W') d[2]++;
        else if(s[i] == 'E') d[3]++;
    }

    if((d[0] == 0 && d[1] > 0) || (d[1] == 0 && d[0] > 0) || (d[2] == 0 && d[3] > 0) || (d[3] == 0 && d[2] > 0))
        cout << "No" << endl;
    else 
        cout << "Yes" << endl;
    return 0;
}