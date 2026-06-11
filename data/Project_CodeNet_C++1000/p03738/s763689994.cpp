#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
string A, B;
cin >> A >> B;
int a = A.size();
int b = B.size();
if(a > b) cout << "GREATER" << endl;
else if(a <b) cout << "LESS" << endl;
else{
    for(int i = 0; i < a; i++){
int ai = A[i];
int bi = B[i];
if (ai > bi){
    cout << "GREATER" << endl; 
    break;
}
else if(ai < bi){
    cout << "LESS" << endl;
    break;
}
else if(i == a-1 && ai == bi) cout << "EQUAL" << endl;
else continue;



    }





}


}

