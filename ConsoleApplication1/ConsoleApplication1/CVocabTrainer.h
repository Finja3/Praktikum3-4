#pragma once
#include "CLesson.h"
#include "CRandomQuery.h"

class CVocabTrainer
{
private:
	CLesson* l = nullptr;
public:
	// Importieren einer neuen Lektion mit Vokabeln, die abgefragt werden sollen.
	bool importLesson(std::string lang, std::string name) {
		if (l != nullptr)				// Wenn l bereits auf eine lesson verweist, ...
			delete l;					// soll diese gelöscht werden

		l = new CLesson(lang, name);	// Eine neue Lektion wird angelegt

		if (l->listLength() == 0) {		// Überprüfe, ob die Lektion leer ist. Wenn ja, ...
			delete l;					// lösche die gerade angelegte Lektion ...
			l = nullptr;				// und überschreibe l sicherheitshalber mit dem nullptr
			return false;
		}

		return true;
	}

	int startQuery(CRandomQuery* q) {
		if (l == nullptr) return 0;		// Wenn noch keine Lektion geladen wurde, stppe Abfrage

		q->linkVocabList(l->getVocabList());

		int cnt = 0;
		do {
			system("cls");
			cnt++;
		} while (q->query());			// Frage solange ab, bis query den Wert false zurückgibt (Abfrage beendet)

		q->queryResults();				// Zeige Ergebnisse der Abfrage an
		system("pause");

		return cnt;
	}
};

