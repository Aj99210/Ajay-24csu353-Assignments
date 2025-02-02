#include <iostream>
#include <string>
#include <set>
#include <algorithm>

void checkPalin(std::string string);
void countFreq(std::string string);
void help(char val, std::string str);
void replaceVowel(std::string& str);

int main() {
	std::string str;

	std::cout << "Enter a string: ";
	std::getline(std::cin>>std::ws, str);

	checkPalin(str);
	countFreq(str);
	replaceVowel(str);

	std::cout << str;
	return 0;
}

void checkPalin(std::string string) {
	char temp;
	std::string original;

	std::transform(string.begin(), string.end(), string.begin(), ::tolower);
	original = string;


	int len = string.length();
	for (int i = 0; i < len / 2; i++) {
		temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}

	if (original == string) { std::cout << "String is palindrome!!\n"; }
	else { std::cout << "String is Not a palindrome!!\n"; }


}

void countFreq(std::string string) {
	int len = string.length();
	std::set<char> check;

	std::cout << "\nFrequencies: \n";
	for (auto element : string) {
		if (element == ' ' || check.count(element)) continue;
		help(element, string);
		check.insert(element);
	}
}

void help(char val, std::string str) {
	char turn = val; int len = str.length();
	int freq = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] == turn) freq++;
	}

	std::cout << turn << ": " << freq << std::endl;
}

void replaceVowel(std::string& str) {
	char symbol;
	std::string vowels = "aeiouAEIOU";
	
	std::cout << "\nEnter the symbol you want to replace vowels with: ";
	std::cin >> symbol;

	for (auto& val : str) {
		if (vowels.find(val) != std::string::npos) { val = symbol; }
	}
	
}