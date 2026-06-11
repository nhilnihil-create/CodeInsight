#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int len;
    long ans = 0;
    string s;
    cin >> s;
    len = s.size();
    vector<long> vc;
    for(int i=0; i<len; i++){
        vc.push_back((long)((int)(s[i]-'0')));
    }
    for(int bit=0; bit<(1<<(len-1)); bit++){
       long tmp = vc[0];
       for(int i=0; i<len-1; i++){
          if(bit & 1<<i){
            ans += tmp;
            tmp = vc[i+1];
          }else{
            tmp *= 10;
            tmp += vc[i+1];
          }
       }
       ans += tmp;
    }

    cout << ans << endl;
    return 0;
}
