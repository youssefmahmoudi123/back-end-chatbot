#pragma once

#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include <vector>

using namespace std;

inline string trim(const string& value)
{
	size_t first = value.find_first_not_of(" \t\r\n");
	if (first == string::npos)
		return "";

	size_t last = value.find_last_not_of(" \t\r\n");
	return value.substr(first, last - first + 1);
}

inline string normaliserTexte(string value)
{
	transform(value.begin(), value.end(), value.begin(),
		[](unsigned char c) { return static_cast<char>(tolower(c)); });

	const vector<pair<string, string>> replacements = {
		{"à", "a"}, {"â", "a"}, {"ä", "a"},
		{"é", "e"}, {"è", "e"}, {"ê", "e"}, {"ë", "e"},
		{"î", "i"}, {"ï", "i"}, {"ô", "o"}, {"ö", "o"},
		{"ù", "u"}, {"û", "u"}, {"ü", "u"}, {"ç", "c"},
		{"œ", "oe"}
	};

	for (const auto& replacement : replacements)
	{
		size_t position = 0;
		while ((position = value.find(replacement.first, position)) != string::npos)
		{
			value.replace(position, replacement.first.length(), replacement.second);
			position += replacement.second.length();
		}
	}

	return value;
}

inline vector<string> separerMotsCles(const string& value)
{
	vector<string> result;
	size_t start = 0;

	while (start <= value.length())
	{
		size_t end = value.find(',', start);
		if (end == string::npos)
			end = value.length();

		string item = trim(value.substr(start, end - start));
		if (!item.empty())
			result.push_back(item);

		if (end == value.length())
			break;
		start = end + 1;
	}

	return result;
}

inline vector<map<string, string>> analyserBlocs(const string& contenu)
{
	vector<map<string, string>> records;
	map<string, string> current;

	auto saveRecord = [&]()
	{
		if (!current.empty())
		{
			records.push_back(current);
			current.clear();
		}
	};

	size_t start = 0;
	while (start <= contenu.length())
	{
		size_t end = contenu.find('\n', start);
		if (end == string::npos)
			end = contenu.length();

		string line = trim(contenu.substr(start, end - start));
		if (line == "---")
		{
			saveRecord();
		}
		else
		{
			size_t separator = line.find(':');
			if (separator != string::npos)
			{
				string key = trim(line.substr(0, separator));
				string value = trim(line.substr(separator + 1));
				if (!key.empty())
					current[key] = value;
			}
		}

		if (end == contenu.length())
			break;
		start = end + 1;
	}

	saveRecord();
	return records;
}
