#include<iostream>
using namespace std;
main()
{
    string s;
    cin>>s;
    int n=s.size();
    cout<< ((n%2==0)^(s[0]==s[n-1])?"Second":"First")<<endl;
    return 0;
}