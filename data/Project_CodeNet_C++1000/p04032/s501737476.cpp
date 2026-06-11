#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int N=1e5+9;
int main()
{
    FASTINOUT;
    string s;
    cin>>s;
    int x=s.size();
    for (int i=1;i<x;i++){
        if (s[i]==s[i-1]){
            cout<<i<<" "<<i+1<<endl;
            return 0;
        }
    }
    for (int i=2;i<x;i++){
        if (s[i]==s[i-2]){
            cout<<i-1<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1;
    return 0;
}
