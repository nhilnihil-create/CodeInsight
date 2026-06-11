#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
 int n,a,b;
    cin>>n>>a>>b;
    
    string s;
    cin>>s;
    
    int counta=0;
    int countb=0;
    
    rep(i,n){
        if(s[i] == 'a' && counta+countb < a+b) {
         cout << "Yes" << endl;
            if(counta < a) {
             counta++;
            }else{
             countb++;
            }
        } else if(s[i] == 'a' && counta+countb >= a+b) {
         cout << "No"<<endl;
        }
        else if(s[i] == 'b' && counta+countb < a+b && countb <b){
         cout << "Yes"<<endl;
            countb++;
        } else if((s[i] == 'b' && counta+countb >= a+b) || (s[i] == 'b'  && countb >=b)) {
         cout << "No"<<endl;
        } else {
         cout << "No"<<endl;
        }
        
        
     }
    

}