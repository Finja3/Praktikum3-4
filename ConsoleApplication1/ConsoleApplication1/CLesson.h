#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>

class CLesson
{
private:
	std::string name;
	std::fstream file;
	std::string language;
	std::unordered_map<std::string, std::string> vocabList;

public:
	// Konstruktor für eine neue Lesson
	CLesson(std::string l, std::string n) : name(n), language(l) {
		std::ifstream f( language + "_" + name + ".txt");		// Öffne die Datei, z.B. "EN_fruits.txt"
		if (f.fail()) return;

		char buf[100];
		while (f.getline(buf, sizeof(buf))) {								// Lese Datei zeilenweise ein
			char* token = strtok(buf, "<>");
			std::string dWord = token;										// speichere das deutsche Wort ...
			token = strtok(NULL, ">");
			std::string fWord = token;										// und das Wort in der Fremdsprache
			vocabList[dWord] = fWord;										// Speichere das Wortpaar in der map
		}

		f.close();															// Schließe die Datei
	}

	// Zeige die Vokabelliste (Wird hier ggf. für Testausgaben genutzt)
	void showVocabList() {
		for (auto it = vocabList.begin(); it != vocabList.end(); ++it) {
			std::cout << std::left << std::setw(20) << it->first
				<< std::setw(20) << it->second << "\n";
		}
	}

	// Gibt eine Referenz auf die Vokabelliste zurück
	const std::unordered_map<std::string, std::string>& getVocabList() {
		return vocabList;
	}

	// Gibt die Länge der Vokabelliste zurück
	int listLength() { return vocabList.size(); }
};

