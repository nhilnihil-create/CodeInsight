#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector<int>v1 = {1,3,5,7,8,10,12};
    vector<int>v2 = {4,6,9,11};
    vector<int>v3 = {2};

    int x,y = 0;
    cin >> x >> y;

    //探索
    auto resultf = find(v1.begin(),v1.end(),x);
    if(resultf == v1.end()){
        auto resultt = find(v2.begin(),v2.end(),x);
        if(resultt == v2.end()){
            cout << "No" << endl;
        }else{
            auto resultty = find(v2.begin(),v2.end(),y);
            if(resultty == v2.end()){
                cout << "No" << endl;
            }else{
                cout << "Yes" << endl;
            }
        }
    }else{
        auto resultfy = find(v1.begin(),v1.end(),y);
        if(resultfy == v1.end()){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }

    return 0;
}
