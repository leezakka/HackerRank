#include <iostream>
#include <stdlib.h>
using namespace std;

// Big Multiplier Function Using String
string Multiplier(string firStr, string secStr) {

	string strTemp;
  string firTemp, secTemp, thiTemp;
	string resTemp;

  int index = 0;
	int carry = 0;
	int maxLen = 0;

	for(int i = secStr.length()-1; i >= 0 ; i--) {
	  for(int j = firStr.length()-1; j >= 0 ; j--) {

			// each index sum
			int intTemp = stoi(firStr.substr(j,1)) * stoi(secStr.substr(i,1)) + carry;

			// omit Carry
			if (intTemp > 9) {
				strTemp = to_string(intTemp % 10);

				if(j==0) {
				  strTemp = to_string(intTemp);
	      }
				// calc Carry
				carry = intTemp/10;

				// get Result index String
				if(index == 0)
				  firTemp.insert(0, strTemp);
				else if (index == 1)
				  secTemp.insert(0, strTemp);
				else
				  thiTemp.insert(0, strTemp);

			// Non-Carry
			} else {
				strTemp = to_string(intTemp);
				carry = 0;

				// get Result index String
				if(index == 0)
				  firTemp.insert(0, strTemp);
				else if (index == 1)
				  secTemp.insert(0, strTemp);
				else
				  thiTemp.insert(0, strTemp);
			}
		}
		index++;
		carry = 0;
	}

	// Append 0 to Calculate SUM to align each length
	secTemp.append("0");
	thiTemp.append("00");
	carry = 0;
 
	/*
  cout<< "First  : " <<firTemp <<endl;
  cout<< "Second : " <<secTemp <<endl;
  cout<< "Third  : " <<thiTemp <<endl;
	*/

	// Calculate SUM
	maxLen = firTemp.length();
	// Get MAX Length
	int tempLen = ( secTemp.length() > thiTemp.length() ) ? secTemp.length() : thiTemp.length();
	maxLen = ( maxLen > tempLen) ? maxLen : tempLen;

	// Fill 0 to STR amount to MAX Length
	if ( firTemp.length() < maxLen ) {
		int fillNum = maxLen - firTemp.length();
		for(int i=0; i<fillNum; i++)
	    firTemp.insert(0, "0"); 
  }
	if ( secTemp.length() < maxLen ) {
		int fillNum = maxLen - secTemp.length();
		for(int i=0; i<fillNum; i++)
	    secTemp.insert(0, "0"); 
  }
	if ( thiTemp.length() < maxLen ) {
		int fillNum = maxLen - thiTemp.length();
		for(int i=0; i<fillNum; i++)
	    thiTemp.insert(0, "0"); 
	};

  //cout<<endl;
	//cout<< "maxLen : " <<maxLen <<endl;
  //cout<< "First  : " <<firTemp <<endl;
  //cout<< "Second : " <<secTemp <<endl;
  //cout<< "Third  : " <<thiTemp <<endl;
	

	// Final Sum
	for(int i = 0; i < maxLen ; i++) {

			int intTemp = stoi(firTemp.substr(firTemp.length()-1 - i, 1)) + stoi(secTemp.substr(secTemp.length()-1 - i, 1)) +
			              stoi(thiTemp.substr(thiTemp.length()-1 - i, 1)) + carry;
			// Omit Carry
			if(intTemp > 9) {
				strTemp = to_string(intTemp % 10);

				if(i == maxLen-1) {
				  strTemp = to_string(intTemp);
	      }
				carry = intTemp/10;

        // Store Result
				resTemp.insert(0, strTemp);

		  // Non-Carry
      } else {
				strTemp = to_string(intTemp);
				carry = 0;
        // Store Result
				resTemp.insert(0, strTemp);
			}
	}

	// Get result 
	//cout << "resTemp : " << resTemp <<endl;
	
	// is First character ZERO?
	if (resTemp.compare(0,1,"0") == 0)
		resTemp = resTemp.substr(1, resTemp.length());

	// Return Result
	return resTemp;
}

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {

	string res;
  string strTemp = to_string(n);

	if (n == 1) {
		cout<<"1"<<endl;
	  exit(0);
	}

	if (n < 1)
		exit(0);

	if (n > 100) {
		cout<<"Out of Range [n<=100]"<<endl;
	  exit(0);
  }

	// First Run
	res = Multiplier(strTemp, to_string(n-1));

	// Factorial
	for (int i = n-2; i > 0; i--)
		res = Multiplier(res, to_string(i));

	// Print result
	cout<<res<<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
