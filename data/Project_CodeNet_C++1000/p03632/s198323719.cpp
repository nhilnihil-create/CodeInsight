#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,D;
    cin >>A>>B>>C>>D;
    int begin=max(A,C);
    int end=min(B,D);
    if(end-begin<0){
        cout <<"0"<<endl;
        return 0;
    }
    cout<<end-begin<<endl;
}
