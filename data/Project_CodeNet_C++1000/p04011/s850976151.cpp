#include<iostream>
using namespace std;
int main(){
int N , K , X , Y;
cin >> N>>K>>X>>Y;
if( X>Y && X<=10000 && N>=K){
X*=K;
Y=Y*(N-K);
cout<<X+Y<<endl;
}
else if(K>N && X>Y &&( X  <=10000)){
    K=N;
    X*=K;
Y=Y*(N-K);
cout<<X+Y<<endl;
}
}
