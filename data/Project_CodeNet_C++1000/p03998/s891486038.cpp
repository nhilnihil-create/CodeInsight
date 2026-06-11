
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string A, B, C;
    cin >> A >> B >> C;

    string next;
    // push_back関数で要素の追加が行える
    next.push_back(A.at(0));

    int a{}, b{}, c{};
    while(true){
        if(next == "a"){
            if(A.empty()){
                cout << "A" << endl;
                break;
            }
            //*はポインタを表す
            next = *A.begin();
            A.erase(A.begin());
            a++;
        }
        if(next == "c"){
            if(C.empty()){
                cout << "C" << endl;
                break;
            }
            //*はポインタを表す
            next = *C.begin();
            C.erase(C.begin());
            c++;
        }
        if(next == "b"){
            if(B.empty()){
                cout << "B" << endl;
                break;
            }
            //*はポインタを表す
            next = *B.begin();
            B.erase(B.begin());
            b++;
        }
    }
}