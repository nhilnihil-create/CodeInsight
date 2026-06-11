#include<bits/stdc++.h>

using namespace std;

class Solve {
    private:
    bool solve(int *syllables) {
        int count5 = 0;
        int count7 = 0;
        for(int i = 0; i < 3; i++) {
            if(syllables[i] == 5) {
                count5++;
            } else if(syllables[i] == 7) {
                count7++;
            }
        }
        if(count5 == 2 && count7 == 1) {
            return true;
        } else {
            return false;
        }
    }
    public:
    void takeInput() {
        int syllableLen[3];
        for(int i = 0; i < 3; i++) {
            cin>>syllableLen[i];
        }
        cout<<(solve(syllableLen)?"YES":"NO")<<endl;
    }
};

int main() {
    Solve s;
    s.takeInput();
    return 0;
}