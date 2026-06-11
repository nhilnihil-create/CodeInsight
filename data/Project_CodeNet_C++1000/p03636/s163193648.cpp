#include <bits/stdc++.h>
#include <string>
using namespace std;

int n,k;
string s;

// outputkan karakter pertama, panjang-2, karakter terakhir

int main(){
    cin>>s;
    n=s.length();
    k=n-2;
    cout<<s[0]<<k<<s[n-1]<<endl;
}