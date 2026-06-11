#include <bits/stdc++.h>
using namespace std ;
int main(){
    string A,B;
    cin >> A >> B;
    int Ak = A.size();
    int Bk = B.size();
    int Ans=-1;
    if(Ak>Bk)Ans=0;
    else if(Ak<Bk)Ans =1;
    else{
        for(int i=0;i<A.size();i++){
            if(A[i]>B[i]){
                Ans =0;
                break;
            }else if(A[i]<B[i]){
                Ans =1;
                break;
            }
        }
    }
    if(Ans==0)cout << "GREATER" << endl;
    else if(Ans ==1)cout << "LESS" << endl;
    else cout << "EQUAL" << endl;
    
 }