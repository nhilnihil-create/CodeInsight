#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    if((int)s.length()&1 == 1) s.pop_back();
    while((int)s.length()){
        string part1 = s.substr(0, (((int)s.length())/2));
        string part2 = s.substr((((int)s.length())/2), (((int)s.length())/2));
        if(part1 == part2 && s.length() != n){
            cout<<(int)s.length()<<endl;
            break;
        }
        s.pop_back();
        s.pop_back();
    }
}