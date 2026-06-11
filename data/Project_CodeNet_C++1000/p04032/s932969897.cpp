#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2<<"\n";return 0;
        }
    }

    for(int i=0;i<s.length()-2;i++){
        if(s[i]==s[i+2] && s[i]!=s[i+1]){
            cout<<i+1<<" "<<i+3<<"\n";return 0;
        }
    }

    cout<<-1<<" "<<-1<<"\n";


    return 0;
}
