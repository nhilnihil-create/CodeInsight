#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//using ll = long long;
//void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    string a,b;
    cin >> a >> b;
    vector<string> n(2);
    n[0] = a;
    n[1] = b;
    sort(n.begin(),n.end());
    if(a.size() > b.size())cout << "GREATER";
    else if(a.size() < b.size()) cout << "LESS";
    else if(a != b && n[1] == a)cout << "GREATER";
    else if(a != b && n[0] == a)cout << "LESS";
    else if (a == b)cout << "EQUAL";
}