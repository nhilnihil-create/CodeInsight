#include <bits/stdc++.h>
using namespace std;
#define fol(i,n) for(int i=0;i<n;i++)

int main(){
    int ans1,ans2;
    int h,w;cin>>h>>w;
    string s;
    fol(i,h){
        fol(j,w){
            cin>>s;
            if (s=="snuke"){
                ans1=j;
                ans2=i;
            }
        }
    }
    cout << (char)('A'+ans1)<<1+ans2<<endl;
    return 0;
}
