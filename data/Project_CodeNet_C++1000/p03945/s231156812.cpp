#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int size=s.size();
    int count=0;
    char now;
    for (int i=0;i<size;i++) {
        if (i==0) {
            now=s[i];
        } else {
            if (s[i]!=now) {
                now=s[i];
                count++;
            }
        }
    }
    cout<<count<<endl;
}
