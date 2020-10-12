/**
 * fileio.cpp
 * Author: Vishal Fenn
 *
 */

#include "../includes/fileio.h"
#include "../includes/constants.h"

using namespace std;
using namespace constants;

bool has_nothing (fstream &efile);

bool openFile (fstream &myfile, const string &myFileName,
		ios_base::openmode mode) {
	myfile.open (myFileName.c_str(), mode);
	if (has_nothing (myfile)) {
		closeFile (myfile);
		return false;
	}
	if (!myfile) {
		return false;
    }
	return true;

}

void closeFile (fstream &myfile) {
	myfile.close();
}

int writetoFile (vector<entry> &entries, const string &outputfilename) {
  
	ofstream openfile;
	openfile.open(outputfilename);

	if (!openfile) {
      return FAIL;
	}
	for (unsigned int i = 0; i < entries.size(); i++) {
		openfile << entries[i].word << " " << entries[i].number_occurences
				<< endl;
	}
	return SUCCESS;
}
	

bool has_nothing (fstream &efile) {
	return efile.peek() << fstream::traits_type::eof();

}

