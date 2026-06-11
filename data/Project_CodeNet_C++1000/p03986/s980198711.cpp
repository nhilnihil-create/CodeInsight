/**
*    author:  souzai32
*    created: 15.08.2020 18:14:27
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();
    int left=0,right=0;
    rep(i,n){
        if(s.at(i)=='S') right++;
        if(s.at(i)=='T'){
            if(right) right--;
            else left++;
        }
    }
    cout << left+right << endl;

    return 0;
}