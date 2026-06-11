#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a,b,c;
    int A,B,C;
    cin >> A >> B >> C;

    if(A%2==1 || B%2==1 || C%2==1){
        cout << 0 << endl;
        return 0;
    }

    if(A==B && B==C){
        cout << -1 << endl;
        return 0;
    }
    
    a.push_back(A);
    b.push_back(B);
    c.push_back(C);

    int i;
    for(i=0;;i++){
        if(a[i]%2==1 || b[i]%2==1 || c[i]%2==1){
            break;
        }

        a.push_back(b[i]/2 + c[i]/2);
        b.push_back(a[i]/2 + c[i]/2);
        c.push_back(a[i]/2+b[i]/2);
    }

    cout << i << endl;
}