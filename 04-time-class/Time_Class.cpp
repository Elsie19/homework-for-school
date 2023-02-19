#include "time.cpp"
#include <iostream>

using namespace std;

int main(void) {
  Time myTime1{};
  Time myTime2{};
  Time myTime4{};
  myTime1.seconds = 1342352;
  myTime2.hours = 0;

  Time myTime3 = myTime1 + myTime2;
  cout << myTime3 << endl;
  myTime4 = myTime4 + 5;
  cout << myTime4 << endl;
  // cout << myTime3 << endl;
}
