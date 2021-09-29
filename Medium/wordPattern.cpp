bool wordPattern(string pattern, string s) {
  int aCharVal = 97;
  string map[26] = {""};
  istringstream ss(s);
  unordered_set <string> wordSet;
  
  int i = 0;
  string curWord;
  while (i < pattern.length() && ss >> curWord){
    char curPatIdx = pattern[i]-aCharVal;
    if(map[curPatIdx].empty()) {
      if(wordSet.count(curWord)){
        return false;
      }
      else {
        map[curPatIdx] = curWord;
        wordSet.insert(curWord);
      }
    } 
    else if(curWord.compare(map[curPatIdx])){
      return false;
    }
    i++;
  }
  if(i < pattern.length() || ss >> curWord) {
    return false;
  }
  else{
    return true;
  }
}