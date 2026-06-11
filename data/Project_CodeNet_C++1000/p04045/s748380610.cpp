#include <bits/stdc++.h>
using namespace std;

bool likeNumber(int num, vector<bool> dislikes) {
    int i = 0;
    int residual;
    while(pow(10,i) <= num) {
        residual = (num / (int)pow(10,i)) % 10;
        if(dislikes.at(residual)) {
            return false;
        }
        num;
        i++;
    }
    return true;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> d(k);
    vector<bool> booleans(10, false);
    for(int i = 0; i < k; i++) {
        cin >> d.at(i);
        booleans.at(d.at(i)) = true;
    }
    while(likeNumber(n,booleans) == false) {
        n++;
    }
    cout << n << endl;
}