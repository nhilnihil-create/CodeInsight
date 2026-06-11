#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF=1001001001;


int main() {
    string n;
    cin>>n;
    string t=n;
    reverse(n.begin(),n.end());
    if(n==t) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}