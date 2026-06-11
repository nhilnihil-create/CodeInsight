#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)


int main(){
    int n;
    cin >> n;
    vector<int> v(5,0);
    rep(i,n){
        int tmp;
        cin >> tmp;
        if (tmp%4 == 0) v[4]++;
        else if (tmp%2 == 0) v[2]++;
        else v[1]++;
    }
    int x,y;
    x = v[1]; y = v[4];
    if (v[2] > 0) x++;

    if (x <= y+1) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}