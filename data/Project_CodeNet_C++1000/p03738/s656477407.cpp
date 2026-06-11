#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    string A,B;
    cin >> A >> B;
    if(A.size()>B.size()){
        cout << "GREATER" <<endl;
    }else if(A.size()<B.size()){
        cout <<"LESS"<<endl;
    }else{
        if((int)A[0] > (int)B[0]){
            cout << "GREATER" <<endl;
        }else if((int)A[0] < (int)B[0]){
            cout << "LESS" <<endl;
        }else{
            cout << "EQUAL" <<endl;
        }
    }
}