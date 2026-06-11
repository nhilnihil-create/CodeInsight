#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c;
  string S;
  int d=0;
  int e=0;
  int i=0;
  cin>>a>>b>>c>>S;
  
  for(int i = 0; i <a; i++){
        switch(S[i]){
            case 'a' :
                if(d<b+c){
                    cout << "Yes" << endl;
                    d++;
                }
                else cout << "No" << endl;
                break;
            case 'b' :
                if(d<b+c&&e<c){
                    cout << "Yes" << endl;
                    d++;
                    e++;
                }
                else cout << "No" << endl;
                break;
            case 'c' :
                cout << "No" << endl;
                break;
 
        }
    }
 
 
  }