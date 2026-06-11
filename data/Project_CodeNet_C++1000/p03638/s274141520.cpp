#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    int h,w,n,i;
    cin >> h >> w >> n;
    vector<int> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<vector<int>> c(h,vector<int>(w));
    int j = 0,k = 0,l;
    for(i = 0;i < n;++i){
        for(l = 0;l < a.at(i);++l){
            c.at(j).at(k) = i+1;
            if(j%2 == 0){
                ++k;
            }else{
                --k;
            }
            if(j%2 == 0 && k == w){
                --k;
                ++j;
            }
            if(j%2 == 1 && k== -1){
                ++k;
                ++j;
            }
        }
    }
    for(i = 0;i < h;++i){
        for(j = 0;j < w;++j){
            cout << c.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}