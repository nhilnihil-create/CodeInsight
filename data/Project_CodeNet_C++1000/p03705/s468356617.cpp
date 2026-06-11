#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long N,A,B;
    while(cin>>N>>A>>B){
        if((N==1 && A!=B) || (A>B)){
            cout<<0<<endl;
        }
        else{
            long long Min=A*(N-1)+B;
            long long Max=A+B*(N-1);
            long long answer=Max-Min+1;
            cout<<answer<<endl;
        }
    }
    return 0;
}