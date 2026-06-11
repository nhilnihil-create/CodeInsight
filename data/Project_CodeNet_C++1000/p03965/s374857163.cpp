#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;
typedef long long ll;


int main(){
        string S;
        cin >> S;
        ll Count_p=0, Point=0;
        for(int i=0; i<S.size(); i++){
                char hand = S[i];
                if(hand == 'g'){
                        if(Count_p>0){
                                Count_p--;
                                Point++;
                        }
                        else{
                                Count_p++;
                        }
                }
                else
                        if(Count_p>0) Count_p--;
                        else{
                                Count_p++;
                                Point--;
                        }
        }
        cout << Point;
}
