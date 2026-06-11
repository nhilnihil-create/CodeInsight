#include <iostream>
using namespace std;
int main(){
        long long int A,B,C;
        cin>>A>>B>>C;
        if(A==B && B==C && A%2==0){
            cout<<-1<<endl;
        }else if(A%2==1 || B%2==1 || C%2==1){
            cout<<0<<endl;
        }else{
            int noTimes = 0;
            while(A%2==0 && B%2==0 && C%2==0){
                long long int tempA = (B/2) + (C/2);
                long long int tempB = (A/2) + (C/2);
                long long int tempC = (A/2) + (B/2);
                A = tempA;
                B = tempB;
                C = tempC;
                noTimes++;
            }
            cout<<noTimes<<endl;
        }
}