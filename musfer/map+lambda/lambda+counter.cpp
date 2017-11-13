#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<char, int> getFreqsFromFile(string fileName) 
{
	char x;
	map<char, int> frequencies;
	ifstream inFile;

	inFile.open("input.txt");
	while (inFile >> x) 
	{
		frequencies[x]++;
	}
	inFile.close();

	return frequencies;
}


void sortVectorPairsSecond(vector< pair<char, int> > & v) {
	auto sortingFunc = [](pair<char, int> x, pair<char, int> y)
	{
		return x.second > y.second;
	};

	sort(v.begin(), v.end(), sortingFunc);
}


void printVectorPairs(const vector< pair<char, int> > & v) {
	for_each(v.begin(), v.end(), [](pair<char, int> x)
	{
		cout << x.first << " was found " << x.second << " times." << endl;
	});
}

int main()
{
	map<char, int> freqs = getFreqsFromFile("input.txt");
	vector< pair<char, int> > freqs_vec(freqs.begin(), freqs.end());
	
	sortVectorPairsSecond(freqs_vec);

	printVectorPairs(freqs_vec);

    return 0;
}

