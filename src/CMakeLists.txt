project(WordsFilter)

#set(KWSYS_ENCODING_DEFAULT_CODEPAGE CP_UTF16)

add_executable(WordsFilterTest main.cpp WordsFilter.cpp) 

set_property(TARGET WordsFilterTest PROPERTY CXX_STANDARD 11)




