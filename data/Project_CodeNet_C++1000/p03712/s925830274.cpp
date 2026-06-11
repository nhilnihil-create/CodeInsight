#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> vec(h);
    for (int i = 0; i < h; i++)
    {
        cin >> vec.at(i);
    }

    for (int i = 0; i < h + 2; i++)
    {
        if (i == 0 || i == h + 1){
            rep(j, w + 2)
            {
                cout << "#";
                if (j == w + 1)
                {
                    cout << "" << endl;
                }
                
            }
        }
        else
        {
            rep(j, 3)
            {
                if (j == 0 || j == 2)
                {
                    cout << "#";
                    if (j == 2)
                    {
                        cout << "" << endl;
                    }
                    
                }
                else
                {
                    cout << vec.at(i - 1);
                }
                
                
            }
        }
        
    }
    
    
}