#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
 
int main() {
    //input
    int n;
    string str,ans; cin >> str;
    n = str.size();
 
    //compute
    for(int i = 0; i < n; i++){
            if(str.at(i) != 'B'){
                ans = ans + str.at(i);
            }else{
                if(ans.empty()){
                }else{
                    int m;
                    m = ans.size();
                    ans.erase(m - 1);
                }
            }
    }

    //output
    cout << ans << endl;
 
}