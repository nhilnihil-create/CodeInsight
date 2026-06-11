#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin>>a>>b;

    if (a > 0)              cout<<"Positive"<<endl;
    else if (b >= 0)        cout<<"Zero"<<endl;
    else if (a%2 == b%2)    cout<<"Negative"<<endl;
    else                    cout<<"Positive"<<endl;
}
