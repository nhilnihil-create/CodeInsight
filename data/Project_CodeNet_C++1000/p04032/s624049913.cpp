#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n=s.length();
    if(n==2 && s[0]==s[1]){
        cout << "1 2";
        return 0;
    }
    for(int i=0;i<n-2;i++){
        if(s[i]==s[i+1] || s[i]==s[i+2]){
            cout << i+1  << " " << i+3 << endl;
            return 0;
        }
    }
    if(s[n-1]==s[n-2]){
        cout << n-1 << " " << n;
        return 0;
    }   
    cout << "-1 -1";

    return 0;
}