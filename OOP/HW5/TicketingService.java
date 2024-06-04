import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;

public class TicketingService {

   public static void main (String[] args) {
      Scanner scnr = new Scanner(System.in);
      String personName = "";
      int counter = 0;
      int youPosition = 0;

      Queue<String> peopleInQueue = new LinkedList<String>();
      personName = scnr.nextLine();
      
      while (!personName.equals("-1")) 
      {
         // Addd personName to peopleInQueue and 
         // determines position of "You"  
         peopleInQueue.add(personName); 
         counter = counter + 1;
         
         if (personName.equals("You"))
            youPosition = counter;  
            
         personName = scnr.nextLine();
      }

      System.out.println("Welcome to the ticketing service... ");
      System.out.println("You are number " + youPosition + " in the queue.");

      /* Removes head person from peopleInQueue, and                                    
      // outputs their name and that they have purchased a ticket,                             
      // then output your position in the queue. When you are at                              
      // the head, output that you can purchase your ticket. */                                 
      for (int i = youPosition - 1; i >= 1; i--) 
      {
         System.out.println(peopleInQueue.remove() + " has purchased a ticket.");
         System.out.println("You are now number " + i);
      }

      System.out.println("You can now purchase your ticket!");
   }
}