// An Ordinary Game
#include <iostream>
#include <string>
using namespace std;

string s;

int main(){
    cin>>s;
    int n=s.size();
    if((n%2==1&&s[0]==s[n-1])||(n%2==0&&s[0]!=s[n-1]))
        cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}