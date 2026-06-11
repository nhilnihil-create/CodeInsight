#include<iostream>
using namespace std;
int main(){
    // int A, B;
    // char op;
    // cin >> A >> op >> B;

    // if(op == '+'){
    //     cout << A + B << endl;
    // }
    // else{
    //     cout << A - B << endl;
    // }

    int time[101], N, M, problem, stim_time, sum = 0;
    cin >> N;
    pair<int, int> after_drink [101];
    for(int i = 1; i <= N; i++){
        cin >> time[i];
        sum += time[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> problem >> stim_time;
        pair<int, int> my_pair(problem, stim_time);
        after_drink[i] = my_pair;
    }
    for(int i = 0; i < M; i++){
        pair<int, int> test = after_drink[i];
        int test_problem = test.first;
        int test_problem_time = test.second;
        int original_time = time[test_problem]; 
        int temp = sum;
        temp += test_problem_time - original_time;
        cout << temp << endl;
    }
}