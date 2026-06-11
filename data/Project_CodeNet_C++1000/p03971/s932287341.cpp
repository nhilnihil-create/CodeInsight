#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b, i=0, j=1, bcount=0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    while(i<n){
        if(s[i] == 'c'){
            cout<<"No"<<endl;
        }
        else if(s[i] == 'a'){
            if(j <= a + b){
                cout<<"Yes"<<endl;
                j++;
            }    
            else
                cout<<"No"<<endl;
        }
        else if(s[i] == 'b'){
            bcount++;
            if(j <= a + b && bcount <= b){
                cout<<"Yes"<<endl;
                j++;
            }    
            else
                cout<<"No"<<endl;    
        }
        i++;
    }
    return 0;
}