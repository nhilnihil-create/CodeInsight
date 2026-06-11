#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin>>s;
    int idx = s.find(",");
    while(idx!=-1){
        s.replace(idx,1," ");
        idx = s.find(",",idx+1);
    }
    cout<<s<<endl;

    return 0;
}
