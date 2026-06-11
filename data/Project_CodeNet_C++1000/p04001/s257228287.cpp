#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef long long int ll;
const int INF = 1001001001;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
/*bit全探索
for (int bit = 0; bit < (1<<N); ++bit) {
}
if (bit & (1 << i)) {
}
*/

bool isPrime(int x){
    if(x==1)return 0;
    if(x==2)return 1;
    if(x%2==0)return 0;
    for(int i=3;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

ll f(string s){
    string a = "";
    ll sum = 0;
    int n = s.size();
    rep(i,n){
        if(s[i]=='+'){
            sum += stoll(a);
            a = "";
        }else{
            a += s[i];
        }
    }
    sum += stoll(a);
    return sum;
} 

int main(){
    string s;
    cin >> s;
    ll sum = 0;
    int n = s.length()-1; 
    rep(bit,1<<n){
        string tmp = "";
        tmp += s[0];
        rep(i,n){
            if(bit&(1<<i)){
                tmp+="+";
            }
            tmp+=s[i+1];
        }
        sum+=f(tmp);
    }
    cout << sum << endl;
    return 0;
}
