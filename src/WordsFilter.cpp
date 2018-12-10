#include "WordsFilter.h"


WordsFilter::WordsFilter()
{
}


WordsFilter::~WordsFilter()
{
}

WordsFilter::WordsFilter(const std::vector<std::string> &words)
{
	_Words = words;
}

void WordsFilter::SetWords(const std::vector<std::string> &words)
{
	_Words = words;
}

void WordsFilter::AddFilterWord(std::string badword, std::string replaceword)
{
	_ReplacingTable.insert(std::pair<std::string, std::string>(badword, replaceword));
}

WordsFilter::WordsFilterErr WordsFilter::ReplaceAll(std::vector<std::string> &words)
{
	if (words.empty()) return WordsFilterErr::WORDS_EMPTY;
	if (_ReplacingTable.empty()) return WordsFilterErr::TABLE_EMPTY;

	for (auto const& item : _ReplacingTable)
	{
		for (auto& word : words)
		{
			std::size_t found = word.find(item.first);
			while (found != std::wstring::npos) {
				word.replace(found, item.first.length(), item.second);
				found = word.find(item.first);
			}
		}
	}
	
	//words = _Words;
	return WordsFilterErr::SUCCESS;
}
