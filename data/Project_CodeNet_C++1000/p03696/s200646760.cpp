#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    int n; cin >> n;
    string s; cin >> s;
    string gs = s;
    
    int l = 0,r = 0;
    rep(i,n){
        if(s[i] == '('){
            for(int j=i+1;j<n;j++){
                if(s[j] == ')'){
                    s[j] = 'e';
                    s[i] = 'e';
                    break;
                }
            }
        }else if(s[i] == ')'){
            for(int j=i-1;j>=0;j--){
                if(s[j] == '('){
                    s[j] ='e';
                    s[i] = 'e';
                    break;
                }
            }
        }
    }

    rep(i,n){
       if(s[i] == ')') r++;
       if(s[i] == '(') l++;
    }   
    string ans = "";
    rep(i,r) cout << '(';
    cout << gs;
    rep(i,l) cout << ')';
    cout << endl;
    return 0;
}