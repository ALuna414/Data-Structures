#include <string>

/**
PSEUDOCODE: 

algorithm MinimumWordLength
  Input: {"hello", "there", "beautiful"} or another array of string words.
  Output: 5 or the number of letters in the shortest word from array.

  Your pseudocode goes here.
    int i
    int count_min = words[0].length()
    if length equals 0:
      return 0
    for i equal to 0 and i less than length():
      if words[index].length is less than count_min:
       count_min = words[index].length
    return count_min

COMMENTS:
From the start I knew I was going to need a for loop to keep count of the minimum
 number of letters in a word. This prompted me to declare two interger values, one
 for i in the for loop and another for the oount and set to zero. Once declared for loop
 was added in which added the lowest word length to the count. Nested an if statement
 to keep lowest word count assigned to the count interger and returned it. Added an if
 statment after so if length was zero then it would return 0.
*/
int MinimumWordLength(std::string words[], int length) {
  // Implement this function.
    int i;
    int count_min = (int)words[0].length();
    
    if (length == 0)
        return 0;
    
    for (i=0; i < length; i++) {
        if (words[i].length() < count_min)
            count_min = (int)words[i].length();
    }
    return count_min;
}

/**
PSEUDOCODE: 

algorithm MaximumWordLength
  Input: {"hello", "there", "beautiful"} or another array of string words.
  Output: 9 or the number of letters in the longest word from array.

  Your pseudocode goes here.
    int i
    int count_max = 0
    if length equals 0:
      return 0
    for i equal to 0 and i less than length:
      if words[index].length() is greater than count_max:
       count_max = words[index].length()
    return count_max

COMMENTS:
Since I figured out the minimum lenght finder, all I had to do was to flip one of the
 condititons to find the max. Same variables were declared but named differently
 and only thing I would change would be in the nested if statement. It would change
 from a less than to a greater than the count original assigned. Then return that value.
*/
int MaximumWordLength(std::string words[], int length) {
  // Implement this function.
    int i;
    int count_max = 0;
    
    if (length == 0)
        return 0;
    
    for (i=0; i < length; i++) {
        if (words[i].length() > count_max)
            count_max = (int)words[i].length();
    }
    return count_max;
}

/**
PSEUDOCODE: 

algorithm RangeOfWordLengths
  Input: {"hello", "there", "beautiful"} or another array of string words.
  Output: 4 or the range of the inputted words by user.

  Your pseudocode goes here.
    int range = 0
    if length equals 0:
     return 0
    else:
      range = MeximumWordLenght call - MinimumWordLength call
    return range

COMMENTS:
This one stumped me at first as I was thinking to hard about. I knew I had to declare an
 int variable of range and set equal to zero. Then as before it would close if length was
 zero since there would be no words traversed through. Since range is a difference between
 highest and lowest, I did exactly that in an else statement just simply calling MaxWordLength
 and subtracting to MinWordLength call. Then assign that to range value and return it.
*/
int RangeOfWordLengths(std::string words[], int length) {
  // Implement this function.
    int range = 0;
    
    if (length == 0)
        return 0;
    else
        range = MaximumWordLength(words, length) -
                MinimumWordLength(words, length);
    
    return range;
}

/**
PSEUDOCODE: 

algorithm WordLengthMean
  Input: {"hello", "there", "beautiful"} or another array of string words.
  Output: 6 or the average of the letters in all words compared.

  Your pseudocode goes here.
    int mean = 0
    if length equals 0:
     return 0
    for i equal to 0 and i less than length:
     mean += words[i].length
    return mean divided by length

COMMENTS:
Just as before I am looking to return a value that is found by now taking the mean of the
 words being traversed. I declared mean as an int value of zero and just like before if the
 length was zero it would exit. Mean means average of all letters in the words so I used a
 for loop and assigned mean to add mean plus the letters of every word coming in to it.
 Once the loop executed I had to return the mean divided by the length of the words in the
 words array.
*/
int WordLengthMean(std::string words[], int length) {
  // Implement this function.
    int mean = 0;
    
    if (length == 0)
        return 0;
    
    for (int i = 0; i < length; i++) {
        mean += words[i].length();
    }
    return mean / length;
}

/**
PSEUDOCODE: 

algorithm WordLengthMode
  Input: {"hello", "there", "beautiful"} or another array of string words.
  Output: 5 or the mode of the different array inputted.

  Your pseudocode goes here.
    int mode = 0
    int max_length
    int max_count
    int curr_length
    int curr_count
    for int i = 0 and i less then the length:
      max_length = 0
      max_count = 0
      curr_length = 0
      curr_count = 0
      curr_length = (int)words[i].length()
    for int j = i + 1 and j less than length:
      if curr_length compares to words[j].length()
        curr_count ++
    if curr_count is greater then max_count
      max_count = curr_count
      max_length = curr_length;
      mode = max_length;
    else if curr_count is greater than max_count and curr_length does not equal max_length and
    max_count doesn't equal 0
      return -1
    return mode
         
COMMENTS:
I really struggled with this one because i had the picture in my head of what to do but couldn't
 translate it to physical code. I slowly ended up piecing it together by just going to the root of the
 problem. Slack also helped as it allowed me to interact with students on how to write down what
 was processing in my head. I ended up needing 5 varialbes in which all were used and named
 accordingly. Then I realized i would haver to implement two for loops so i can array through
 the first word and store the number of it. Then if another word had the same number it would add
 to a count which would be the mode. Also needed to implement if statements to do this. Lastly,
 had to satisfy the condition in the rubric of returning -1 if there is a tie. 
*/
int WordLengthMode(std::string words[], int length) {
  // Implement this function.
    int mode = 0, max_length, max_count;
    int curr_length, curr_count;
    
    for (int i = 0; i < length; i++) {
        max_length = 0;
        max_count = 0;
        curr_length = 0;
        curr_count = 0;
        curr_length = (int)words[i].length();
        
        for (int j = i + 1; j < length; j++) {
            if (curr_length == words[j].length())
                curr_count++;
        if (curr_count > max_count){
            max_count = curr_count;
            max_length = curr_length;
            mode = max_length;
        }
        else if (curr_count > max_count && curr_length != max_length && max_count != 0)
            return -1;
        }
    }
    return mode;
}
