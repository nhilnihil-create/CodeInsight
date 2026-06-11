#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n';

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, max_w;
    cin >> n >> max_w;

    vector<int> vector0, vector1, vector2, vector3;
    int w1,v,w;
    cin >> w1 >> v;
    vector0.push_back(v);
    for(int i=0; i<n-1; i++){
        cin >> w >> v;
        switch(w-w1){
            case 0:
                vector0.push_back(v);
                break;
            case 1:
                vector1.push_back(v);
                break;

            case 2:
                vector2.push_back(v);
                break;

            case 3:
                vector3.push_back(v);
                break;
        }
    }

    //cout << vector0.size() << vector1.size() << vector2.size() << vector3.size() << endl;

    sort(vector0.begin(), vector0.end(), greater<int>());
    sort(vector1.begin(), vector1.end(), greater<int>());
    sort(vector2.begin(), vector2.end(), greater<int>());
    sort(vector3.begin(), vector3.end(), greater<int>());

    int max = 0, tmp;
    //cout << max_w << endl;
    long long int w_sum;

    for(int i=0; i<=vector0.size(); i++){
        for(int j=0; j<=vector1.size(); j++){
            for(int k=0; k<=vector2.size(); k++){
                for(int l=0; l<=vector3.size(); l++){
                    w_sum = (long long int)w1*i + (long long int)(w1+1)*j + (long long int)(w1+2)*k + (long long int)(w1+3)*l;
                    if(w_sum > (long long int)max_w){
                        continue;
                    }
                    
                    tmp = accumulate(vector0.begin(), vector0.begin()+i, 0) 
                        + accumulate(vector1.begin(), vector1.begin()+j, 0)
                        + accumulate(vector2.begin(), vector2.begin()+k, 0)
                        + accumulate(vector3.begin(), vector3.begin()+l, 0);
                    //cout << tmp << endl;
                    if(max < tmp){
                        max = tmp;
                    }

                }
            }
        }
    }

    cout << max << endl;

    return 0;
}