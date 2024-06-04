public class Pair <TheType extends Comparable<TheType>> {
   private TheType firstVal;
   private TheType secondVal;

   
   /*Initialize the public fields firstVal to aVal and secondVal to bVal */
   public Pair(TheType aVal, TheType bVal) {
      this.firstVal = aVal;
      this.secondVal = bVal; 
   }

   /* Return a string representation of the pair in the format "[firstVal, secondVal]" */
   public String toString() {
      return "[" + firstVal + ", " + secondVal + "]";
   }

   /* Implement Comparable's expected compareTo()
   // Returns -1, 0, or 1 according to whether the Pair is less than, equal to, or greater than otherPair
   // Precedence of comparisons: firstVal, then secondVal */
   public int compareTo(Pair<TheType> otherPair) {
      if (firstVal.compareTo(otherPair.firstVal) < 0)
         return -1;
      if (firstVal.compareTo(otherPair.firstVal) > 0)
         return 1; 
         
      if (secondVal.compareTo(otherPair.secondVal) < 0)
         return -1;
      if (secondVal.compareTo(otherPair.secondVal) > 0)
         return 1;
      
      return 0; 
   }

   /* Returns '<', '=', or '>' according to the ordering of this pair and otherPair */
   public char comparisonSymbol(Pair<TheType> otherPair) {
      if (firstVal.compareTo(otherPair.firstVal) < 0)
         return '<';
      if (firstVal.compareTo(otherPair.firstVal) > 0)
         return '>';
         
      if (secondVal.compareTo(otherPair.secondVal) < 0)
         return '<';
      if (secondVal.compareTo(otherPair.secondVal) > 0)
         return '>';

      return '=';
   }
}