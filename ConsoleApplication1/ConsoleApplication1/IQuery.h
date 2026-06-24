#pragma once
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>

// Abstrakte Basisklasse (Schnittstelle) fuer alle Abfragemodi.
// Sie buendelt die Eigenschaften und Methoden, die alle Abfragemodus-Klassen
// gemeinsam haben bzw. fuer die Verwendung in CVocabTrainer::startQuery()
// bereitstellen muessen.
class IQuery
{
private:
	std::unordered_map<std::string, std::string> dummy;

protected:
	std::unordered_map<std::string, std::string>& m;

	std::set<std::string> wrongAnswers;

public:
	IQuery() : m(dummy) {}

	virtual ~IQuery() = default;

	virtual void linkVocabList(const std::unordered_map<std::string, std::string>& list) = 0;

	virtual bool query() = 0;

	virtual void queryResults() {
		if (wrongAnswers.size() == 0)
			std::cout << "Du hast keinen Fehler gemecht!\n";
		else {
			std::cout << "Von " << m.size() << " vokabeln hast du "
				<< wrongAnswers.size() << " falsch beantwortet.\n";
			std::cout << "Die folgenden Vokabeln kannst du dir nochmal anschaun: \n";
			for (const auto& i : wrongAnswers)
				std::cout << i << " - " << m.at(i) << "\n";
		}
	}
};