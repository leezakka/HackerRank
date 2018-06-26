#include "/Users/huming/Dropbox/Workspace/stdc++.h"
using namespace std;

void plusMinus(vector<int> arr) {

	int totalCnt = arr.size();

  float posNum = 0.0f, negNum = 0.0f, zeroNum = 0.0f;

  for(int i =0; i < arr.size(); i++) {
     if (arr[i]>0)
        posNum++;
     else if (arr[i]<0)
        negNum++;
     else
        zeroNum++;
  }

  cout<< (posNum/totalCnt) <<endl;
  cout<< (negNum/totalCnt) <<endl;
  cout<< (zeroNum/totalCnt) <<endl;
}

int main()
{

	int n;
	cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);

  for (int arr_itr = 0; arr_itr < n; arr_itr++) {
        cin >> arr[arr_itr];
  }

  plusMinus(arr);	

	return 0;
}
