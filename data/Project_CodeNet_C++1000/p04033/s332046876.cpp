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
    int a, b;
    cin >> a >> b;

    if((a<0 && b>0)||(a>0 && b<0)||a==0||b==0) cout << "Zero" << endl;
    else if(a>0 && b>0) cout << "Positive" << endl;
    else if((b-a+1)%2 == 0) cout << "Positive" << endl;
    else cout << "Negative" << endl;
    return 0;
}