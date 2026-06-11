#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    //数値を numbers　に代入
    int N;
    cin >>N;
    vector<int> numbers(N) ;
    for(int i=0;i<N;i++){
        numbers.at(i)=(i+1);
    }
    // 1からNまでのなかで、2で割れるものを探す
    int trial_num=0;
    for(int i=0;i>=0;i++){
        bool finished =  false;
        for(int j=0;j<N;j++){
            int b = (numbers.at(j) % 2);
            if(b==1){
            }
            else{
                numbers.at(j) = (numbers.at(j)/2);
                finished = true;
            }
        }
        
        if(finished){
            trial_num = trial_num + 1;
        }
        else{
            break;
        }
        
    }

    int answer = 1;
    for(int i=0;i<trial_num;i++){
        answer = 2 * answer;
    }
    cout << answer << endl;
}