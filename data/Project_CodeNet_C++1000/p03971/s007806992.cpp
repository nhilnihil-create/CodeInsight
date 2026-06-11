#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    int A,B;
    cin >> A>>B;
    string N;
    cin >> N;
    int YES = 0;
    int YESb= 0;
    for(int i=0;i<T;++i){
        if(N.at(i)=='a' && YES<(A+B)){
            cout << "Yes"<<endl;
            ++YES;
        }
        else if (N.at(i)=='b' && YES<(A+B)&&YESb<B){
            cout << "Yes"<<endl;
            ++YES;
            ++YESb;
        }
        else{
            cout << "No" <<endl;
        }
    }
}