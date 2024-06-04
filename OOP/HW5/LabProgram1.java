import java.util.Scanner;

public class LabProgram {
   public static Pair<Integer> readIntegerPair(Scanner scnr) {
      int a, b;
      
      a = scnr.nextInt();
      b = scnr.nextInt();
      
      Pair<Integer> intPair = new Pair< >(a, b);
      return intPair; 
   }

   public static Pair<Double> readDoublePair(Scanner scnr) {
      double x, y;
      
      x = scnr.nextDouble();
      y = scnr.nextDouble();
      
      Pair<Double> doublePair = new Pair< >(x, y);
      return doublePair; 
   }

   public static Pair<String> readWordPair(Scanner scnr) {
      String m, n;
      
      m = scnr.next();
      n = scnr.next();
      
      Pair<String> stringPair = new Pair< >(m, n);
      return stringPair;
   }

   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);

      Pair<Integer> integerPair1 = readIntegerPair(scnr);
      Pair<Integer> integerPair2 = readIntegerPair(scnr);

      Pair<Double> doublePair1 = readDoublePair(scnr);
      Pair<Double> doublePair2 = readDoublePair(scnr);

      Pair<String> wordPair1 = readWordPair(scnr);
      Pair<String> wordPair2 = readWordPair(scnr);

      /* Prints out the pairs ans outputs the two Pair objects separated by the character */
      System.out.println(integerPair1 + " " + integerPair1.comparisonSymbol(integerPair2) 
                        + " " + integerPair2);
      System.out.println(doublePair1 + " " + doublePair1.comparisonSymbol(doublePair2) 
                        + " " + doublePair2);
      System.out.println(wordPair1 + " " + wordPair1.comparisonSymbol(wordPair2) 
                        + " " + wordPair2);
   }
}
