#include <vector>
#include <string>
#include "WordsFilter.h"
#include <iostream>

int main()
{
	WordsFilter wf = WordsFilter();
	wf.AddFilterWord("ROC", "RPC");
	wf.AddFilterWord("456", "***");

	std::string word1 = "ROC is a nice nation";
	std::string word2 = "1234567890";
	std::vector<std::string> words{ word1, word2 };
	wf.ReplaceAll(words);

	std::string respectword1 = "RPC is a nice nation";
	std::string respectword2 = "123***7890";

	if (words[0] == respectword1)
		std::cout << "pass" << std::endl;
	if (words[1] == respectword2)
		std::cout << "pass" << std::endl;

	return 0;
}

