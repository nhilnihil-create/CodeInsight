#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

char maze[51][51];

int main(){
    int x,a,b;
    cin >> x >> a >> b;
    if (b <= a ) cout << "delicious" << endl;
    else if (b > a && b-a <= x) cout << "safe" << endl;
    else cout << "dangerous" << endl; 
       
    return 0;
}