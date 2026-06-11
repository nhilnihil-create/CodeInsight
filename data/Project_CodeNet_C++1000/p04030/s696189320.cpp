#include <iostream>
using namespace std;

void solve(){

    string value ;
    string output;

    cin>>value;
    int len = value.length();

    for(int i=0 ;i<len;i++){
        if(value.at(i) == '0'){
            output.push_back('0');
        }else if(value.at(i) == '1'){
            output.push_back('1');
        }else if(value.at(i) == 'B' && !output.empty()){
            output.pop_back();
        }
    }
    cout<<output<<endl;

}

int main()
{
    int TestCases=1;
    while(TestCases >0){
        solve();
        TestCases--;
    }

    return 0;
}
