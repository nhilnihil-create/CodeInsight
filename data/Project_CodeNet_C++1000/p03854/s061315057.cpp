#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n=s.size();
    reverse(s.begin(), s.end());
    while(s.size()!=0){
        if(s.substr(0,6)=="resare") s=s.substr(6);
        else if(s.substr(0,5)=="esare") s=s.substr(5);
        else if(s.substr(0,7)=="remaerd") s=s.substr(7);
        else if(s.substr(0,5)=="maerd") s=s.substr(5);
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}