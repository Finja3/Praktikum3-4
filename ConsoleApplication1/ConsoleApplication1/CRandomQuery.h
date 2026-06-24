#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <random>
#include "IQuery.h"

class CRandomQuery : public IQuery
{
private:
	std::vector<std::string> vFirst;
public:
	void linkVocabList(const std::unordered_map<std::string, std::string>& list) override {
		m = list;

		for (auto& i : m)
			vFirst.push_back(i.first);

		std::shuffle(vFirst.begin(), vFirst.end(), std::random_device());
	}

	bool query() override {
		if (vFirst.empty()) return false;

		std::string answer, rightAnswer = m.at(vFirst.back());

		std::cout << "Vokabel " << m.size() - vFirst.size() + 1 << " von " << m.size() << "\n";
		std::cout << vFirst.back() << " >> ";
		std::getline(std::cin, answer);

		if (answer == rightAnswer)
			std::cout << "Klasse! Das war richtig.\n";
		else {
			std::cout << "Deine Antwort '" << answer << "' war leider falsch! Die richtige Antwort ist '" << rightAnswer << "'.\n";
			wrongAnswers.insert(vFirst.back());
		}

		system("pause");
		vFirst.pop_back();
		return true;
	}

	
};

