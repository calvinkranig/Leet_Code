public class Main
{
  /*
  There is a string, , of lowercase English letters that is repeated infinitely
  many times. Given an integer, , find and print the number of letter a's in 
  the first  letters of the infinite string.

  Example
  s = 'abcac'
  n = 10

  The substring we consider is abcacabcac the first 10 characters of the 
  infinite string. There are 4 occurrences of 'a' in the substring.

  Function Description:

  repeatedString has the following parameter(s):
    s: a string to repeat
    n: the number of characters to consider
  
  Returns:
    long: the frequency of a in the substring
  */
    public static long repeatedString(String s, long n) {
        long lCount = 0;
        long totCount = 0;
        long repCount = n/s.length();
        long modCount = n%s.length();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i)=='a'){
                totCount++;
                if(i<modCount) {
                   lCount++; 
                }
            }
        }
        return totCount*repCount+lCount;
    }
    
	public static void main(String[] args) {
		System.out.println(repeatedString("aba",10));
	}
}