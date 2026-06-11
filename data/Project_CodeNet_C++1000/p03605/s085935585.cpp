#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if(N/10 == 9 ){
      cout << "Yes" << endl;
    }
    else if(N-N/10*10 == 9) {
      cout <<"Yes"<< endl;
    }
    else {
      cout <<"No"<<endl;
    }
}

