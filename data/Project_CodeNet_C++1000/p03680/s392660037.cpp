#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);

    rep(i, N){
        cin >> vec.at(i);

    }
    int light = 1;
    int count = 0;
    bool goal = false;
    rep(i, N)
    {
        light = vec.at(light - 1);
        count += 1;
        if (light == 2)
        {
            goal = true;
            break;
        }
    }

    if (goal)
    {
        cout << count << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    
    
}