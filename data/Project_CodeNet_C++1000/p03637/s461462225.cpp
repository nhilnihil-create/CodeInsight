#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
using namespace std;


int main () {
    int n;
    cin >> n;
    int cnt1=0;
    int cnt2=0;
    int cnt4=0;
    for (int i=0;i<n;i++){
        int m;
        cin >> m;
        if (m%4==0) cnt4+=1;
        else if (m%2==0) cnt2+=1;
        else cnt1+=1;
    }
    int ans;
    if (cnt2>=1) {
        if(cnt1<=cnt4){
            cout << "Yes";
        }
        else cout << "No" ;
    }
    else {
        if (cnt1<=cnt4+1){
            cout << "Yes";
        }
        else cout << "No" ;
    }
}