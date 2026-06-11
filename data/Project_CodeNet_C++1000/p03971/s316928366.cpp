#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int sum=a+b;
    int foreigner=0;
    for (int i=0;i<n;i++) {
        if (s[i]=='c') {
            cout<<"No"<<endl;
        } else if (s[i]=='a') {
            if (sum>0) {
                cout<<"Yes"<<endl;
                sum--;
            } else {
                cout<<"No"<<endl;
            }
        } else if (s[i]=='b') {
            if (sum>0&&foreigner<b) {
                cout<<"Yes"<<endl;
                sum--;
                foreigner++;
            } else {
                cout<<"No"<<endl;
            }
        }
    }
}