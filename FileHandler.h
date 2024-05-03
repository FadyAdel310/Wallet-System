#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class FileHandler {
public:
	static void WriteInFile(string filePath, int recordsNum, string dataList[]) {
		ofstream newFile(filePath);
		for (int i = 0; i < recordsNum; i++) {
			newFile << dataList[i] << endl;
		}

		newFile.close();
	}

	static vector<string> ReadFromFile(string filePath) {
		ifstream newFile(filePath);
		int counter = 0;
		int numOfRecords = DetermineNumberOfRecords(filePath);
		string currentText;
		if (numOfRecords != 0) {
			vector<string> dataList;
			while (getline(newFile, currentText)) {
				dataList.push_back(currentText);
				counter++;
			}

			return dataList;
		}
		else {
			cout << "No Data in File" << endl;
		}
	}

	static int DetermineNumberOfRecords(string filePath) {
		ifstream newFile(filePath);
		int counter = 0;
		string currentText;

		while (getline(newFile, currentText)) {
			if (currentText != "") {
				counter++;
			}
		}
		return counter;
	}
};