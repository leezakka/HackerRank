#include <iostream>
#include <vector>
#define MAX_IDX 7
using namespace std;

// hourglass range
int dx[7] = {-1, 0, 1, 0, -1, 0, 1};
int dy[7] = { 1, 1, 1, 0, -1,-1,-1};

// get MAX value
int findMaxSum(vector<int> vecSum) {

  int curVal = vecSum[0];
   
  for (int i=1; i<vecSum.size(); i++) {
    if (curVal < vecSum[i]) {
      curVal = vecSum[i];
    }
  }

  return curVal;
}

int hourglassSum(vector<vector<int> > arr) {

  vector<int> vecSum;
  int totSum=0;
  int maxHourSum = 0;
  int cx=1, cy=1; // Start Point

  for (int y=0; y<4; y++) { // Max Moving Range
  	for (int x=0; x<4; x++) {
 			for (int i=0; i<MAX_IDX; i++) { // idx Search
		    //cout<<arr[cy+y+dy[i]][cx+x+dx[i]] <<" ";
        totSum += arr[cy+y+dy[i]][cx+x+dx[i]];
      }
      //cout<<"totSum["<<totSum<<"]"<<endl;
      vecSum.push_back(totSum);
      totSum = 0;
    }
    //cout << endl;
  }

  return maxHourSum = findMaxSum(vecSum);
}

int main() {

  // input range
  int arrInt[6][6] = { {1,1,1,0,0,0},
                       {0,1,0,0,0,0},
                       {1,1,1,0,0,0},
                       {0,0,2,4,4,0},
                       {0,0,0,2,0,0},
                       {0,0,1,2,4,0} };

  vector<vector<int> > arr(6);

  for (int i=0; i<6; i++) {
  	arr[i].resize(6);
  
    for (int j=0; j<6; j++) {
      arr[i][j] = arrInt[i][j];
    }
  }

  int result = hourglassSum(arr);
  cout<<"result : "<<result<<endl;

  return 0;
}
