#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    rep(i,s1.length()){
        cout << s1[i];
      	if(i<s2.length())cout << s2[i];
    }
    cout << endl;
}
