# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
 
  int n, capacity, late;
  cin >> n >> capacity >> late;
  
  int time[100005];
  for(int i=0; i<n; i++) cin >> time[i];
  sort(time, time+n);
  
  int ans = 1, currentCap = 1, firstPerson = time[0];
  for(int i=1; i<n; i++){
    if(currentCap + 1 <= capacity && time[i] <= firstPerson + late){
      currentCap++;
    } else {
      ans++;
      currentCap = 1;
      firstPerson = time[i];
    }
  }
  
  cout << ans << endl;
  
  return 0;
} 

