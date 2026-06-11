#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N=S.length();
    int i=0,j;
    int check=0;

    while(check==0){
        j=0;
        i++;
        while(1){
            if(S[j]!=S[(N/2-i+j)])break;
            j++;
            if(j==N/2-i){
                check=1;
                break;
            }
        }
    }

    cout << 2*j << endl;

    return 0;
}