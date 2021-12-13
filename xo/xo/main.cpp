#include <iostream>
#include "my_lib.h"
using namespace std;

int main() {
	//подключаем русский €зык
	setlocale(LC_ALL, "rus");
	//выделение пам€ти под поле
	int size = 3;
	char** field = new char* [size];
	for (int i = 0; i < size; i++) {
		field[i] = new char[size];
	}
	//заполн€ем поле пробелами
	init_field(field, size);
	//основной игровой цикл
	while (true) {
		// ход крестиков
		player_turn(field, size);
		//печать пол€
		print_field(field, size);
		// если выигрыш крестиков, то вывести сообщение и прервать цикл
		if (check_win(field, size, 'x')) {
			cout << "¬ыиграли крестики!" << endl;
			break;
		}
		// если ничь€, то вывести сообщение и прервать цикл
		if (check_draw(field, size)) {
			cout << "Ќичь€(((" << endl;
			break;
		}
		// ход ноликов
		player_turn(field, size);
		// печать пол€
		print_field(field, size);
		// если выигрыш ноликов, то прервать цикл
		if (check_win(field, size, 'o')) {
			cout << "¬ыиграли нолики!" << endl;
			break;
		}
		// если ничь€, то прервать цикл
		if (check_draw(field, size)) {
			cout << "Ќичь€(((" << endl;
			break;
		}
	}
	return 0;
}