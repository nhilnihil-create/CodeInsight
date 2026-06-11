#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

int main(){
    IOS;

    string s,ans;
    cin >> s; 
    int n = s.length();
    for(int i=0;i<n;i+=2){
        ans.push_back(s[i]);
    }
    cout << ans << endl;
    return 0;
}