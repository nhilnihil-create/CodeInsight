#include <iostream>

using namespace std;

int main() {
    
    string a,b,c;
    cin>>a>>b>>c;
    int al=a.length();
    int bl=b.length();
    
    if (a[al-1] == b[0] && b[bl-1] == c[0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    
    return 0;
}