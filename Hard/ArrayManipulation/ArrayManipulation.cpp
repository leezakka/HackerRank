#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Get MAX value 
long findMaxSum(vector<long> vecSum) {

  long curVal = vecSum[0];
   
  for (int i=1; i<vecSum.size(); i++) {
    if (curVal < vecSum[i]) {
      curVal = vecSum[i];
    }
  }

  return curVal;
}
// Devide and Qonquer
long findMaxSumDC(vector<long> vecSum, long low, long high) {

  long mid = (high+low)/2;

  if (low == high) 
    return vecSum.at(low);
    //return vecSum[low];

  long l_max = findMaxSumDC(vecSum, low  , mid);
  long r_max = findMaxSumDC(vecSum, mid+1, high);

  return (l_max > r_max) ? l_max : r_max;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int> > queries) {

  int row = queries.size();
  int col = queries[0].size();
  long maxVar = 0;

  // Initailize
  vector<long> outVec(n);

  // O(n^2)
  for (int i = 0; i < row; i++) {
    int st = queries[i][0];
    int ed = queries[i][1];
    for(int idx = st-1; idx < ed; idx++)
      outVec[idx] += queries[i][2];
  }

  // Get MAX Value - O(n)
  //return maxVar = findMaxSum(outVec);
  
  long low = outVec[0];
  long high = outVec[n-1];

  cout<<"low : "<<low<<endl;
  cout<<"high : "<<high<<endl;
 
  return maxVar = findMaxSumDC(outVec, low, high);
  

  // O(n^2) + O(n) = Time out..
}

int main()
{
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int> > queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    cout << result << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
