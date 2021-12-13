#include <iostream>
using namespace std;
void init_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			field[i][j] = ' ';
		}
	}
}
void print_field(char** field, int size) {
	for (int i = 0; i < size; i++) {
		cout << "|---|---|---|" << endl;
		for (int j = 0; j < size; j++) {
			cout << "| " << field[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << "|---|---|---|" << endl;
}
void player_turn(char** field, int size) {
	int row, col;
	char sign;
	do {
		do {
			cout << "Ââåäèòå íîìåð ñòðîêè ";
			cin >> row;
		} while (row < 0 || row > size - 1);
		do {
			cout << "Ââåäèòå íîìåð ñòîëáöà ";
			cin >> col;
		} while (col < 0 || col > size - 1);
	} while (field[row][col] != ' ');
	do {
		cout << "Ââåäèòå çíà÷îê (àíãëèéñêèå x èëè o) ";
		cin >> sign;
	} while (sign != 'x' && sign != 'o');
	field[row][col] = sign;
}
bool check_win(char** field, int size, char sign) {
	if (field[0][0] == sign && field[0][1] == sign && field[0][2] == sign) { return true; } 
	if (field[1][0] == sign && field[1][1] == sign && field[1][2] == sign) { return true; } 
	if (field[2][0] == sign && field[2][1] == sign && field[2][2] == sign) { return true; } 
	if (field[0][0] == sign && field[1][0] == sign && field[2][0] == sign) { return true; } 
	if (field[0][1] == sign && field[1][1] == sign && field[2][1] == sign) { return true; }
	if (field[0][2] == sign && field[1][2] == sign && field[2][2] == sign) { return true; }
	if (field[0][0] == sign && field[1][1] == sign && field[2][2] == sign) { return true; } 
	if (field[0][2] == sign && field[1][1] == sign && field[2][0] == sign) { return true; }
	return false;
}
bool check_draw(char** field, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; i < size; j++) {
			if (field[i][j] == ' ') return false;
		}
	}
	return true;
}