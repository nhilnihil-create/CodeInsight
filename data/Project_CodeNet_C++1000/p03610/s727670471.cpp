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

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int l=s.size();

    if (l%2==0){
        for(int i=0;i<s.size()/2;i++){
            int a= 2*i;
            cout << s[a];
        }   

    }
    else{
        for(int i=0;i<=s.size()/2;i++){
            int a= 2*i;
            cout << s[a];
        }
    }


    return 0;
}