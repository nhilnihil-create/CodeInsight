#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    int co_4 = 0, co_2 = 0, co_1 = 0;
    for (int i = 0; i < N; i++){
        if (a.at(i)%4 == 0) co_4++;
        else if (a.at(i)%2 == 0) co_2++;
        else co_1++;
    }
    
    bool can = false;
    if ((co_4 >= co_1) || (co_4 == co_1 - 1 && co_2 == 0)) can = true;
    
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
}
