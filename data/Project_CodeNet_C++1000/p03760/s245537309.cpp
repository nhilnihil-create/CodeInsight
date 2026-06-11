#include<iostream>
#include<string>

using namespace std;

int main(){
    string o, e, a;
    int olen, elen;

    cin >> o >> e;
    olen = o.size();
    elen = e.size();

    for(int i = 0; i < olen; i++){
        a.push_back(o[i]);
        if(i < elen) a.push_back(e[i]);
    }

    cout << a << endl;
}