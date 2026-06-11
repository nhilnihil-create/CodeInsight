#include <bits/stdc++.h>
using namespace std;
 
int main(){

    int n;
    cin >> n;

    vector<int> data;
    for (int i = 0; i<n; i++){
        int a;
        cin >> a;

        data.push_back(a);
    }

    sort(data.begin(), data.end());

    int check = 0;
    for (int i = 0; i<data.size(); ){
        int count = 1;
        if (i+1 <= n-1){
            while(data.at(i) == data.at(i+1)){
                count++;
                i++;
                if (i+1 > n-1){
                    break;
                }
            }
        }

        if (count%2 != 0){
            check++;
        }

        i++;
    }

    cout << check << endl;

}
