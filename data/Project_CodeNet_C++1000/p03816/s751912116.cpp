#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;

int main()
{
    int n,i;
    cin >> n;
    vector<int> a(n);
    
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    vector<pair<int,int>> p;
    int now = a.at(0);
    int number = 1;
    for(i = 1; i < n;++i){
        if(a.at(i) != now){
            p.emplace_back(now,number);
            now = a.at(i);
            number = 1;
        }else{
            ++number;
        }
    }
    p.emplace_back(now,number);
    int temp = 0;
    for(i = 0;i < p.size();++i){
        if(p.at(i).second % 2 == 0){
            ++temp;
        }
    }
    if(temp%2 == 0){
        cout << p.size() << endl;
    }else{
        cout << p.size()-1 << endl;
    }
    return 0;
}