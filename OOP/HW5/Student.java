public class Student implements Comparable<Student>{
   private String firstName;
   private String lastName;
   private double GPA;
   
   public String first;
   public String last;
   public double gradeAverage;
   
/* Student(first, last, gradeAverage) - set firstName to parameter first, lastName to 
parameter last, and GPA to parameter gradeAverage */
public Student(String first, String last, double gradeAverage) {
   firstName = first;
   lastName = last;
   GPA = gradeAverage; 
}

/* compareTo(otherStudent) - to enable sorting of Student objects, return -1, 0, or 1 
according to the comparisons of the private members between Student and otherStudent. 
Precedence of comparisons: GPA (highest first), then lastName (lowest first), then 
firstName (lowest first) */
@Override
public int compareTo(Student otherStudent) {
   if(GPA > otherStudent.GPA)
      return -1;
   if(GPA < otherStudent.GPA)
      return 1;
   if(lastName.compareTo(otherStudent.lastName) != 0)
      return lastName.compareTo(otherStudent.lastName);
      
   return firstName.compareTo(otherStudent.firstName);
} 

/*toString() - return a string representation of a student in the format "GPA lastName, firstName" */
@Override
public String toString() {
   return String.format("%.2f", GPA) + " " + lastName + ", " + firstName; 
}

}