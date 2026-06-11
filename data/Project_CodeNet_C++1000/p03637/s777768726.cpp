#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    cin>>n;
    int count=0,count2=0;
    for (int i=0;i<n;i++) {
        cin>>a;
        if (a%4==0) {
            count++;
        } else if (a%2==0) {
            if (count2==0) {
                count2++;
            } else {
                count++;
                count2--;
            }
        }
    }
    if (count>=n/2) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}
