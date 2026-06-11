#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    int needed[3] = {0,0,0}; //5,5,7
    for(int i=0;i<3;i++) {
        if(a[i]==5) {
            if(needed[0]==1 && needed[1]==1) {
                cout<<"NO";
                return 0;
            }
            if(needed[0]==0) needed[0]=1;
            else needed[1]=1;
                
                }
        else if(a[i]==7) {
            if(needed[2]==1) {
                cout<<"NO";
                return 0;
            }
            needed[2]=1;
        }
        
        
    }
    for(int i=0;i<3;i++) {
        if(needed[i]!=1) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
