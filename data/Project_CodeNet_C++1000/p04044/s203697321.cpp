#include <iostream>

#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
//const char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// input - given string
// You need to update in the given string itself i.e. in input. No need to return or print.


void solver() {
    // Write your code here
    int n;
    cin>>n;

    int l;
    cin>>l;
    vector<string > my;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        my.push_back(s);
    }
    sort(my.begin(),my.end());
    for(int i=0;i<n;i++)
    {
        cout<<my[i];
    }

















}


int main() {
    int n=1;
    //cin>>n;
    while(n--)
    {
        solver();
    }
}
