#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {

  int index;
  vector<int> temp(n);

  for(int i=0; i<n; i++) {
    index = i - k;
    if(index < 0)
      index = index + n;
    temp[index] = a[i];
  }
  return temp;
}

int main(){
  int n;
  int k;
  cin >> n >> k;
  vector<int> a(n);
  for(int a_i = 0;a_i < n;a_i++){
    cin >> a[a_i];
  }
  vector<int> output = array_left_rotation(a, n, k);
  for(int i = 0; i < n;i++)
    cout << output[i] << " ";
  cout << endl;
  return 0;
}
