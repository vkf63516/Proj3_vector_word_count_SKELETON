/**
 * array_function.cpp
 * Author: Vishal Fenn
 */

#include "../includes/array_functions.h"
#include "../includes/constants.h"
#include "../includes/utilities.h"
#include <algorithm>

using namespace std;
using namespace constants;

namespace KP {
	bool ascendComp(const entry &firstEntry, const entry &seconEntry);
	
	bool descendComp(const entry &firstEntry, const entry &seconEntry);
	
	bool numOfTimes(const entry &firstEntry, const entry &seconEntry);

	void clear(vector<entry> &entries) {
		entries.clear();
	}
	int getSize(vector<entry> &entries) {
		return entries.size();
	}

	string getWordAt(vector<entry> &entries, int i) {
		return entries.at(i).word;
	}

	int getNumbOccurAt(vector<entry> &entries, int i) {
		if (entries.size() == 0) {
			return FAIL;
		}
		return entries.at(i).number_occurences;
	}

	bool processFile(vector<entry> &entries, fstream &myfstream) {
		if (!myfstream) {
			return false;
		}
		string line1;
		while (getline(myfstream, line1)) {
			processLine(entries, line1);
		}
		return true;

	}

	void processLine(vector<entry> &entries, string &myString) {
		string tokenTemp;
		stringstream myStr(myString);
		while (getline(myStr, tokenTemp, CHAR_TO_SEARCH_FOR)) {
			processToken(entries, tokenTemp);
		}
	}	

	void processToken(vector<entry> &entries, string &token) {
		if (strip_unwanted_chars(token) == false) {
			return;
		}
		string nToken = token;
		toUpper(nToken);
		int num1 = -1;
		for (unsigned int i = 0; i < entries.size(); i++) {
			string user = entries[i].word_uppercase;
			if (user == nToken) {
				num1 = i;
				break;
			}
		}
		if (num1 != -1) {
			entries[num1].number_occurences++;
		}
		else {
			entry newEntry { token, nToken, 1 };
			entries.push_back(newEntry);
		}
	}
	void sort(vector<entry> &entries, sortOrder so) {
		if (so == NONE) {
			return;
		}
		if (so == ASCENDING) {
			sort(entries.begin(), entries.end(), ascendComp);
		}
		if (so == DESCENDING) {
			sort(entries.begin(), entries.end(), descendComp);
		}
		if (so == NUMBER_OCCURRENCES) {
			sort(entries.begin(), entries.end(), numOfTimes);
		}
	}
	
	bool ascendComp(const entry &firstEntry, const entry &seconEntry) {
		return firstEntry.word_uppercase < seconEntry.word_uppercase;
	}
	
	bool descendComp(const entry &firstEntry, const entry &seconEntry) {
		return firstEntry.word_uppercase > seconEntry.word_uppercase;
	}
	
	bool numOfTimes(const entry &firstEntry, const entry &seconEntry) {
		return firstEntry.number_occurences > seconEntry.number_occurences;
	}

}
