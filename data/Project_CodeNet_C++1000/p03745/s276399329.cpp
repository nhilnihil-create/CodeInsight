# include <iostream>
# include <map>
using namespace std;

const int NEUTRAL = 0;
const int ASCENDING = -1;
const int DESCENDING = 1;

int main(){
  int N, numbers[100005];
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> numbers[i];
  }
  
  int flag = NEUTRAL;
  int ans = 1;
  for(int i=0; i<N-1; i++){
    if((flag == ASCENDING && numbers[i] > numbers[i+1]) || 
       (flag == DESCENDING && numbers[i] < numbers[i+1])) {
          ans++;
          flag = NEUTRAL;
       }
    else if(numbers[i] < numbers[i+1]) flag = ASCENDING;
    else if(numbers[i] > numbers[i+1]) flag = DESCENDING;
  }
  
  cout << ans << endl;
  
  return 0;
} 