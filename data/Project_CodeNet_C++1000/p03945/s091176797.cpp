#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    string s;
    cin >> s;
    for(int i=0;i<s.size();){
       int j=i;
       while(j<s.size()&&s[j]==s[i]) j++;
       ans++;
       i = j;
    }
    cout << ans-1 << endl;
}
