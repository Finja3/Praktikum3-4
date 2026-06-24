#include <cstdlib>
#include "CLesson.h"
#include "CVocabTrainer.h"
#include "CRandomQuery.h"

int main() {
	system("chcp 1252"); system("cls");

	CVocabTrainer t;
	bool b = t.importLesson("EN", "fruits");
	t.startQuery(new CRandomQuery());

	return EXIT_SUCCESS;
}