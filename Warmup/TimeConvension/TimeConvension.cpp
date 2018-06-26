#include "/Users/huming/Dropbox/Workspace/stdc++.h"
#include <stdlib.h>
#define HOUR 12
#define MINUTE 60
#define DELIMETER ":"

enum {
	eHour,
	eMinute,
	eSecond,
};

using namespace std;
string timeConversion(string s) {
		
  string hh, mm, ss;
  string outStr;
	int Modifier = 0;
	int intTemp = 0;
	int intHour = 0;

	char *str = new char [s.length()+1];
	strcpy(str, s.c_str());
	char *pch;
	char chrTemp[10];

	// Find PM
	if(s.compare(8,2, "PM") == 0) {

    pch = strtok (str, DELIMETER);

		while(pch != NULL)  {
			// Store
			intTemp = 0;
			intTemp = atoi(pch);

			// HH 
		  if(Modifier == eHour) {

				// Exception
				if((intTemp < 1) || (intTemp > 12))
					exit(0);

				// 24 HOUR SETTING
			  intHour = intTemp + HOUR;
				sprintf(chrTemp, "%d", intHour);

				// Exception
				if(intTemp == 12)
				  sprintf(chrTemp, "%d", intTemp);

				hh = chrTemp;

 			// MM 
		  } else if (Modifier == eMinute) {

				// Exception
				if(intTemp < 0)
					exit(0);

				if(intTemp > 59) {
					// MINUTE SETTING
					intTemp = intTemp - MINUTE;  // 72 = 72 - 60 = 12

					// HOUR SETTING
					intHour = intHour + 1;
				  sprintf(chrTemp, "%d", intHour);
				  hh = chrTemp;
				}

				// Exception
			  sprintf( chrTemp, "%d", intTemp);
				if(intTemp < 10)
					mm = mm + "0";

			  mm.append(chrTemp);

			// SS 
			} else {

				// Exception
				if (intTemp > 59)
					exit(0);

				// Exception
				sprintf( chrTemp, "%d", intTemp);
				if(intTemp < 10)
					ss = ss + "0";

				ss.append(chrTemp);
			}
			pch = strtok(NULL, DELIMETER);
			Modifier++;
		}
  
    // Final Check
	  intTemp = atoi(hh.data());
	  if (intTemp > 23)
	  	exit(0);

	  outStr.append(hh);
	  outStr.append(DELIMETER);
	  outStr.append(mm);
	  outStr.append(DELIMETER);
	  outStr.append(ss);
  }
	// AM
	else  {

		// Default Case
	  outStr = s.substr(0,8);

		// Exception
		if(outStr.compare(0,2, "12") == 0) {
			string tempStr = outStr.substr(2,6);
			outStr = "00";
			outStr.append(tempStr);
	  }
  }

	// Clear 
	delete [] str;
	return outStr;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

		cout << result << endl;
    //fout << result << "\n";

    //fout.close();

    return 0;
}
