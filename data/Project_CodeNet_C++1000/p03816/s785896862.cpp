#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,i,A,c=0,r=0;
    cin >> N;
    map<int,int> t;

    for(i=0; i<N; i++) {
        cin >> A;
        if(t.count(A))
            t.at(A)++;
        else
            t[A] = 1;
    }

    for(auto p : t)
        if(p.second%2 == 0)
            c++;
    if(c%2)
        r--;

    cout << t.size()+r << endl;
}