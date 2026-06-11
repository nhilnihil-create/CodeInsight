#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int aa,bb,cc;
    int count = 0;
    for (size_t i = 0; i < 10000; i++)
    {
        if(a%2==1||b%2==1||c%2==1){
            cout << count << endl;
            return 0;
        }
        aa=a/2;
        bb=b/2;
        cc=c/2;
        a=bb+cc;
        b=aa+cc;
        c=aa+bb;
        count++;
        /* code */
    }
    cout << -1<<endl;
    
    
    return 0;
}