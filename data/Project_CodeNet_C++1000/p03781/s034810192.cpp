#include <iostream>
using namespace std;

int main(){
    long long X;
    cin >> X;
    
    long long longest=0;
    for(long long i=1; ; i++){
        longest+=i;
        if(longest>=X){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
