#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    if(N==1){
        cout << 1<<endl;
        return 0;
    }
    int count=0;
    for(int i=0;i<10;++i){
       ++count;
        N/=2;
        if(N==1||N==0){
            break;
        }
    }
    int rui=1;
    for(int i=0;i<count;i++){
        rui*=2;
    }
    
    cout << rui << endl;
}