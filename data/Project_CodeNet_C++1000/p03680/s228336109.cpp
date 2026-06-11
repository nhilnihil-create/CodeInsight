# include<bits/stdc++.h>
using namespace std;

/*int main (){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec.at(i);
    }
    int s = vec.at(1);
    int count = 0;
    for(int i=0;i<N-2;i++){
        count += 1;
        if (s != 2){
            if(vec.at(s) != 2){
                s = vec.at(s);
            }else{
                break;
            }
        }else{
            break;
        }
    }
    
    if(s == 2){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
    
}
*/
int main(){
    int N;
    cin >> N;
    vector<int> vec(N,0);
    for(int i=0; i<N; i++){
        cin >> vec.at(i);
    }
    int s = 1;
    int count = 0; 
    while(s != 2){
        s = vec.at(s-1);
        count += 1;
        if(count > N){
            break;
        }
    }
    if(count < N){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
}