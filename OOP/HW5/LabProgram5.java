import java.util.Scanner;
import java.util.LinkedList;
import java.util.Deque;

public class LabProgram {

   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);
      int j;
      String input = scnr.nextLine();
      String line = input.replaceAll("\\s+", "");  //remove white space
      
      Deque<Integer> linkedDeque = new LinkedList<>();
      boolean isPalindrome = true;
      
      //add characters in line to deque in int form (no punctuation)
      for(int i = 0; i < line.length(); i++)
      {
         if((int)line.charAt(i) >= 97 && (int)line.charAt(i) <= 122)
            linkedDeque.add( (int)line.charAt(i) );
      }
      
      while(linkedDeque.size() > 1)
      {
         if(linkedDeque.getFirst() != linkedDeque.getLast())
         {
            isPalindrome = false;
            break;
         }
         
         linkedDeque.removeFirst();
         linkedDeque.removeLast();
      }
      
      if(isPalindrome)
         System.out.println("Yes, \"" + input + "\" is a palindrome.");
      else
         System.out.println("No, \"" + input + "\" is not a palindrome.");
   }
}