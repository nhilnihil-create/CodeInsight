#include <iostream>

using namespace std;

int main()
{
    int A,B;
    cin>>A>>B;

        if(A==B)
            cout<<"Draw";
        else if(A>B){
            if(B==1)
                cout<<"Bob";
            else if(B!=1)
                cout<<"Alice";
        }
        else if(B>A){
            if(A==1)
                cout<<"Alice";
            else if(A!=1)
                cout<<"Bob";
        }


    return 0;
}