/*
      author  : nishi5451
      created : 14.08.2020 13:54:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    int len = s.size();
    len -= 2;
    while(len){
        string l,r;
        l = s.substr(0,len/2);
        r = s.substr(len/2,len/2);
        if(l==r){
            cout << len << endl;
            return 0;
        }
        len -=2;
    }
    return 0;
}