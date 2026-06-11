//CF
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    regex regex("^YAKI");
    cin>>S;
    if ( regex_search(S, regex) )   cout<<"Yes"<<endl;
    else                            cout<<"No"<<endl;
    return 0;
}