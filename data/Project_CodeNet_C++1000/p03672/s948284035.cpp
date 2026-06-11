#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.length(),flag=0,i;
    //cout<<n<<endl;
    if(n%2==0)
        n=n-2;
    else
        n=n-1;
    //cout<<n<<endl;
    while(1) {
        for (i = 0; i < n/2; i++) {
             if(s[i]!=s[n/2+i]) {
                 //if(n==6) {
                //     cout << s[i] << endl;
                //     cout << s[n / 2 + (i)] << endl;
                // }
                     flag = 1;
                     break;
             }
        }
        if(flag==0) {
            cout<<n<<endl;
            break;
        }
        else {
            flag=0;
            n = n - 2;
        }
       // cout<<n<<endl;
    }
    return 0;
    }
