#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    string s;
    cin>>s;
    long long int  len = s.length();
    long long int a[26]={0};
    for(int i=0;i<s.length();i++)
        a[s[i]-'a']++;
    long long int ans = len*(len-1)/2;
    for(long long int i=0;i<26;i++)
        ans -= ((a[i]*(a[i]-1))/2);
    cout<<ans+1;
    return 0;
}