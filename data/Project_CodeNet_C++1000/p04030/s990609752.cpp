#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
cin>>s;
for(int i=1;i<=s.size();i++){
    regex reg("0B");
    s=regex_replace(s,reg,"");
    regex regex1("1B");
    s=regex_replace(s,regex1,"");

}
    regex regex2("B");
    s=regex_replace(s,regex2,"");



    cout<<s<<endl;
    return 0;
}

