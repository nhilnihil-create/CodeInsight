#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
#define int long long

signed main(){
    int A,B,C;
    cin >> A >> B >> C;
    
    if(A<=C && C<=B){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
