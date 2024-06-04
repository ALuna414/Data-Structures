import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class LabProgram {

   // Input 5 Integers and return the Integers in an ArrayList
   /* inputIntegers()
      Take a scanner as a parameter
      Read 5 integers from a user
      Store the integers in an ArrayList of type Integer
      Return the ArrayList 
   */
   public static ArrayList<Integer> inputIntegers(Scanner scnr) {
      ArrayList<Integer> intList = new ArrayList<Integer>();
      
      for(int i = 0; i < 5; i++)
      {
       intList.add(scnr.nextInt());   
      }
      return intList; 
   }

   // Input 5 Doubles and return the Doubles in an ArrayList
   public static ArrayList<Double> inputDoubles(Scanner scnr) {
      ArrayList<Double> doubleList = new ArrayList<Double>();
      
      for(int i = 0; i < 5; i++)
      {
       doubleList.add(scnr.nextDouble());   
      }
      return doubleList; 
   }

   // Input 5 Strings, and return the Strings in an ArrayList
   public static ArrayList<String> inputWords(Scanner scnr) {
      ArrayList<String> stringList = new ArrayList<String>();
      
      for(int i = 0; i < 5; i++)
      {
       stringList.add(scnr.next());   
      }
      return stringList;
      
   }

   // Output the elements of the ArrayList parameter
   public static <TheType extends Comparable<TheType>>
      void print(ArrayList<TheType> list) {
       for (TheType element : list) 
       {
            System.out.print(element + " ");
       }
       
       System.out.println(); 
   }

   // Return the min, median, and max of the ArrayList parameter in a new ArrayList
   public static <TheType extends Comparable<TheType>>
      ArrayList<TheType> getStatistics(ArrayList<TheType> list)
   {
      Collections.sort(list);
      
      ArrayList<TheType> stats = new ArrayList<TheType>(); 
      
      stats.add(list.get(0));
      stats.add(list.get(2));
      stats.add(list.get(4));
      
      return stats;
   }

   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);

      // Input a list of 5 Integers and print the ArrayList's statistics
      ArrayList<Integer> integers = inputIntegers(scnr);
      print(integers);
      ArrayList<Integer> integerStatistics = getStatistics(integers);
      print(integerStatistics);
      System.out.println();

      // Input a list of 5 Doubles and print the ArrayList's statistics
      ArrayList<Double> doubles = inputDoubles(scnr);
      print(doubles);
      ArrayList<Double> doubleStatistics = getStatistics(doubles);
      print(doubleStatistics);
      System.out.println();

      // Input a list of 5 words (Strings) and print the ArrayList's statistics
      ArrayList<String> words = inputWords(scnr);
      print(words);
      ArrayList<String> wordStatistics = getStatistics(words);
      print(wordStatistics);
   }
}