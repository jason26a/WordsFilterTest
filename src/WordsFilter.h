#pragma once
#include <vector>
#include <string>
#include <map>

class WordsFilter
{	
	std::vector<std::string> _Words;
	std::map<std::string, std::string> _ReplacingTable;

public:
	enum class WordsFilterErr {
		SUCCESS = 0,
		WORDS_EMPTY,
		TABLE_EMPTY
	};

	WordsFilter();
	WordsFilter(const std::vector<std::string> &words);
	virtual ~WordsFilter();

	void SetWords(const std::vector<std::string> &words);

	void AddFilterWord(std::string badword, std::string replaceword);
	
	WordsFilterErr ReplaceAll(std::vector<std::string> &words);


};

