/**
 * Read file ``sample.txt`` and count the number of occurences 
 * for every unique symbol. PLot sorted in descending order.
 */

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "task3_adt_lam.h"

using namespace std;

/**
 * @brief      Read file and contruct ``map`` of frequencies.
 * Keys are unique symbols, values are number of occurences.
 *
 * @param[in]  fileName  The name of file to read from
 *
 * @return     map of symbol/occurences
 */
map<char, int> getFreqsFromFile(string fileName) {
	char x;
	map<char, int> frequencies;
	ifstream inFile;

	inFile.open("../sample.txt");
	while (inFile >> x) {
		// 0 is default contructor for `int`
		frequencies[x]++;
	}
	inFile.close();

	return frequencies;
}

/**
 * @brief      Sort vector of pair by second value in-place
 *
 * @param      v     vector of pairs
 */
void sortVectorPairsSecond(vector<pair<char, int>>& v) {
	auto sortingFunc = [](pair<char, int> x, pair<char, int> y)
	{
		return x.second > y.second;
	};

	sort(v.begin(), v.end(), sortingFunc);
}

/**
 * @brief      Print vector of pairs
 *
 * @param[in]  v     vector of pairs
 */
void printVectorPairs(const vector<pair<char, int>>& v) {
	for_each(v.begin(), v.end(), [](pair<char, int> x)
	{
		cout << x.first << " was found " << x.second << " times." << endl;
	});
}

int main()
{
	map<char, int> freqs = getFreqsFromFile("sample.txt");
	vector<pair<char, int>> freqs_vec(freqs.begin(), freqs.end());
	
	sortVectorPairsSecond(freqs_vec);

	printVectorPairs(freqs_vec);

    return 0;
}

