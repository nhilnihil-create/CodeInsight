#include <bits/stdc++.h>
using namespace std;
int main(void){
    string n;
    cin>>n;
    int flag=0;
    for (int i=0;i<n.size();i++) {
        if (n.at(i)=='9') {
            cout<<"Yes"<<endl;
            flag=1;
            break;
        }
    }
    if (flag==0) {
        cout<<"No"<<endl;
    }
}
