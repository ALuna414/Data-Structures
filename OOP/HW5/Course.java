public class Course implements Comparable<Course> {
   private String department;
   private int number;
   
   public String dept;
   public int num;

/* Course(dept, num) - set department to parameter dept and number to parameter num */
public Course (String dept, int num) {
   department = dept;
   number = num;
}

/*compareTo(otherCourse) - to enable sorting of Course objects, return -1, 0, or 1 according 
to the comparisons of the private members between Course and otherCourse. Precedence of 
comparisons: department (lowest first), then number (lowest first) */
@Override
public int compareTo (Course otherCourse) {
   if(department.compareTo(otherCourse.department) != 0)
      return department.compareTo(otherCourse.department);
   else if (number < otherCourse.number)
      return -1;
   else if(number > otherCourse.number)
      return 1;
      
   return 0;
}

/* toString() - return a string representation of a course in the format "department number" */
@Override
public String toString() {
   return department + " " + number; 
}

}