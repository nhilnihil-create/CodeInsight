#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int a,b,c;
    string s;
    cin >> a >> b >> c;
    cout << a+b+c-max({a,b,c}) << endl;
   

    return 0;
}