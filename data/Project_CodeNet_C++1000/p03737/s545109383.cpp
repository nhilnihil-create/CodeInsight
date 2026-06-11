#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2,s3;
    int henkan = 'A'-'a';
    cin >> s1 >> s2 >> s3;
    char a=s1.at(0)+henkan;
    char b=s2.at(0)+henkan;
    char c=s3.at(0)+henkan;
    cout << a << b << c << endl;
}