#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int> > a) {

  int totNumA = 0, totNumB = 0;

	for(int i=0; i< a.size(); i++) {
		for(int j=0; j< a.size(); j++) {

	    totNumA += (i==j) ? a[i][j] : 0;
		}
		totNumB += a[i][a.size()-i-1];
  } 
  return abs( totNumA - totNumB );
}

int main() {

	int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int> > a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    cout<<"RES : " << result<<endl;

	return 0;
}
