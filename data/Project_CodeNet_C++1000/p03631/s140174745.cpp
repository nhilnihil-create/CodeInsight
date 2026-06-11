#include <bits/stdc++.h>
using namespace std;
int main(){
    string N;
    cin >>N;
    string n=N;
    reverse(N.begin(),N.end());
    if(N==n){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout << "No"<<endl;
}
