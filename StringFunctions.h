#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class StringFunctions {
public:
	static vector<string> split(string str, char delimiter) {
		vector<string> itemList;
		size_t start = 0;
		size_t end = str.find(delimiter);
		while (end <= str.length()) {
			itemList.push_back(str.substr(start, end - start));
			start = end + 1;
			end = str.find(delimiter, start);
		}
		itemList.push_back(str.substr(start));
		return itemList;
	}
};