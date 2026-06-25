#include <cstdlib>
#include "CLesson.h"
#include "CVocabTrainer.h"
#include "CRandomQuery.h"
#include "COnceCorrectQuery.h"

int main() {
	system("chcp 1252"); system("cls");

	CVocabTrainer t;
	bool b = t.importLesson("EN", "household");
	t.startQuery(new COnceCorrectQuery());

	return EXIT_SUCCESS;
}