#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  for (;;) {
    cout << "Enter number: ";
    string num;
    cin >> num;

    if (num == ".") {
      cout << "Number entered is not a float" << endl;
      continue;
    }

    float num_as_float = stof(num);
    float whole_part = trunc(num_as_float);

    int pos_of_decimal = num.find(".");
    int len = num.length();

    // Check if decimal is at the end
    if (len == pos_of_decimal + 1) {
      printf("%s\n", "Invalid input!");
      continue;
    }

    float whole = 0.0;
    float frac = modf(num_as_float, &whole);

    if (frac == 0.0) {
      cout << "Number entered is an integer" << endl;
      continue;
    }

    string decimal_num_str = num.substr(pos_of_decimal + 1);
    int decimal_num = stoi(decimal_num_str);

    int power = pow(10, decimal_num_str.length());

    int int_whole_part = (int)whole_part;
    int int_decimal_num = (int)decimal_num;

    int denom = power;

    while (int_decimal_num % 5 == 0 && denom % 5 == 0) {
      int_decimal_num /= 5;
      denom /= 5;
    }
    while (int_decimal_num % 2 == 0 && denom % 2 == 0) {
      int_decimal_num /= 2;
      denom /= 2;
    }

    if (int_whole_part == 0) {
      cout << int_decimal_num << "/" << denom << endl;
    } else {
      cout << int_whole_part << " " << int_decimal_num << "/" << denom << endl;
    }
  }
}
