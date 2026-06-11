#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    long long A,B,C,X,Y,count;
    cin>>A>>B>>C;
    count=0;
    if(A==B&&B==C){
        if(A%2==0){
            cout<<-1<<endl;
            return 0;
        }
        if(A%2==1){
            cout<<count<<endl;
            return 0;
        }
    }
    else{
        while(A%2==0&&B%2==0&&C%2==0){
            X=A;
            Y=B;
            A=Y/2+C/2;
            B=C/2+X/2;
            C=X/2+Y/2;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
