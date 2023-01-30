#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  double num = 0.0;
  double tol = 0.000001;
  cout << "Enter number: ";
  cin >> num;
  double current_number = num;
  double inverse_decimal = 0.1;

  vector<int> nums;

  while (inverse_decimal > tol) {
    double inverse = 1. / current_number;
    int a = inverse;               // Whole number part
    inverse_decimal = inverse - a; // Decimal part
    nums.push_back(a);
    current_number = inverse_decimal;
  }

  vector<int> N(nums.size());
  vector<int> D(nums.size());

  N[nums.size() - 1] = 1;
  D[nums.size() - 1] = nums.back();

  for (int i = nums.size() - 2; i >= 0; --i) {
    N[i] = D[i + 1];
    D[i] = D[i + 1] * nums[i] + N[i + 1];
  }

  cout << N[0] << "/" << D[0] << endl;
}
