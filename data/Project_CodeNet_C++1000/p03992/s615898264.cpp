#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (n);i++)
typedef long long ll;
typedef pair<int,int> P;
const int MOD = 1000000007;

int main(){
    string s;
    string subA,subB;
    cin >>s;
    rep(i,4)subA.push_back(s[i]);
    for(int i = 4;i < 12;i++)subB.push_back(s[i]);
    cout << subA << " " << subB << endl;
}