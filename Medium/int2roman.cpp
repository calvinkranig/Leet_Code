class Solution {
public:
  static const int MAX_DIVISOR = 1000;
  static const int NUM_SYMBOLS = 4;
  const char pow10Symbols[NUM_SYMBOLS] = {'I','X','C','M'};
  const char mult5Symbols[NUM_SYMBOLS-1] = {'V','L','D'};
  
  
  string intToRoman(int num) {
    int curNum = num;
    int divisor = MAX_DIVISOR;
    int curSymItr = NUM_SYMBOLS-1;
    
    string ret = "";
    while(curNum != 0) {
      int curLeft = curNum/divisor;
      curNum %= divisor;
      switch (curLeft) {
        case 0:
          break;
        case 1:
        case 2:
        case 3:
          ret += string(curLeft, pow10Symbols[curSymItr]);
          break;
        case 4:
          ret += pow10Symbols[curSymItr];
          ret += mult5Symbols[curSymItr];
          break;
        case 5:
          ret += mult5Symbols[curSymItr];
          break;
        case 6:
        case 7:
        case 8:
          ret += mult5Symbols[curSymItr];
          ret += string(curLeft-5, pow10Symbols[curSymItr]);
          break;
        case 9:
          ret += pow10Symbols[curSymItr];
          ret += pow10Symbols[curSymItr+1];
          break;
      }
      divisor /= 10;
      curSymItr--;
    }
    return ret;
  }
};