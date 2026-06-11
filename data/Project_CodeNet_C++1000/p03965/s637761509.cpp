#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std; 


int main(){
    string s;
    cin >> s;
    long long g = 0, p = 0, ans = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'p'){
            if(p + 1 <= g){
                p++;
            }
            else{
                ans--;
                g++;
            }
        }
        else{
            if(p + 1 <= g){
                p++;
                ans++;
            }
            else{
                g++;
            }
        }
    }
    cout << ans;
}
