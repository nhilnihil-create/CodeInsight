#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    char a=s1.at(s1.size()-1);
    char b=s2.at(0);
    char c=s2.at(s2.size()-1);
    char d=s3.at(0);
    if(a==b&&c==d){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}