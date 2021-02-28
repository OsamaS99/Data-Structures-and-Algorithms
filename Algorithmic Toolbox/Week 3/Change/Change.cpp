#include <iostream>
#include <cmath>

int get_change(int m) {
	const int ten{ 10 };
	const int five{ 5 };
	const int one{ 1 };
	int coins = 0;
	int rest = m;
	while (rest > 0) {
		if (rest >= ten) {
			int tens = (int)ceil(rest / ten);
			coins += tens ;
			rest -= tens * ten;
		}
		else if (rest >= five) {
			int fives = (int)ceil(rest / five);
			coins += fives;
			rest -= fives * five;
		}
		else if(rest >= 1){
			int ones = (int)ceil(rest / one);
			coins += ones;
			rest -= ones * one;
		}
	}
	return coins;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
