#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,L;
    cin >> N >> L;
    vector<string> vec(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }

    sort(vec.begin(),vec.end());

    string str = vec.at(0);

    for(int j=1;j<N;j++){
        str += vec.at(j);
    }

    cout << str << endl;
}