# Project 1 Submission
This is the original markdown document that I used to write my project 1 
assignment (before transferring it all to a Microsoft Word document). It 
includes the instructions for the assignment.


# Directions
In the milestones leading to this project, you wrote a description for the 
course object that will be stored in different data structures. To determine 
the running time of each of those data structures in this application, you 
must finish writing all the pseudocode for the rest of the code and perform a 
Big O analysis. 

**Specifically, you must address the following rubric criteria:**

## Pseudocode

1. **Resubmit pseudocode from previous pseudocode assignments and update as 
   necessary.** In the previous assignments, you created pseudocode for each of 
   the three data structures: vector, hash table, and tree. Be sure to resubmit 
   the following pseudocode for each data structure:
   - Design pseudocode to define how the program opens the file, reads the data 
     from the file, parses each line, and checks for formatting errors.
   - Design pseudocode to show how to create course objects so that one course 
     object holds data from a single line from the input file.
   - Design pseudocode that will print out course information and 
     prerequisites.

2. **Create pseudocode for a menu.** The menu will need to perform the 
   following actions:
   - Option 1: Load the file data into the data structure. Note that before 
     you can print the course information or the sorted list of courses, you 
     must load the data into the data structure.
   - Option 2: Print an alphanumerically ordered list of all the courses in 
     the Computer Science department.
   - Option 3: Print the course title and the prerequisites for any 
     individual course.
   - Option 9: Exit the program.

3. **Design pseudocode that will print out the list of the courses in the 
   Computer Science program in alphanumeric order.** Continue working with the 
   Pseudocode Document linked in the Supporting Materials section. Note that 
   you will design for the same three data structures that you have been 
   using in your previous pseudocode milestones: vector, hash table, and tree
   . This time, you will create the final pieces of pseudocode that you will 
   need for ABCU’s advising program. To complete this part of the process, do 
   the following actions:
    - Sort the course information by alphanumeric course number from lowest 
      to highest.
    - Print the sorted list to a display.

## Evaluation

4. Evaluate the run time and memory of data structures that could be used to 
   address the requirements. In previous assignments, you created pseudocode to 
   define how the program opens the file, reads the data from the file, parses 
   each line, and checks for formatting errors and to show how to create course 
   objects so that one course object holds data from a single line from the 
   input file.
   - Using the pseudocode you wrote for the previous assignments, analyze the 
     worst-case running time of each, reading the file and creating course 
     objects, which will be the Big O value. This analysis should not include 
     the pseudocode written for the menu or the search/print functions Print 
     Course List (Option 2) above. To complete this part of the project, do 
     the following actions:
     - Specify the cost per line of code and the number of times the line 
       will execute. Assume there are n courses stored in the data structure.
     - Assume the cost for a line to execute is 1 unless it is calling a 
       function, in which case the cost will be the running time of that 
       function.

5. Based on the advisor’s requirements, analyze each of the vector, hash table, 
   and tree data structures. **Explain the advantages and disadvantages of each 
   structure in your evaluation**.

6. Now that you have analyzed all three data structures, make a 
   recommendation for which data structure you plan to use in your code. 
   Provide justification for your recommendation based on the Big O analysis 
   results and your analysis of the three data structures.

# Milestones
Resubmit your pseudocode for the Milestones One, Two, and Three assignments, 
and update it as necessary based on the feedback you received. In these 
assignments, you already created pseudocode for each of the three data 
structures:

 - Milestone One: Vector 
 - Milestone Two: Hash Table
 - Milestone Three: Binary Search Tree

*Be sure to resubmit all three milestones that had the following components:*

 - Pseudocode designed to define how the program opens the file, reads the 
   data from the file, parses each line, and checks for formatting errors 
 - Pseudocode designed to show how to create course objects so that one 
   course object holds data from a single line from the input file
 - Pseudocode designed to find and print out course information and 
   prerequisites for a single course

This submission is graded with the Final Project Part I Rubric below.

# What to Submit
To complete this project, you must submit the following item:

## Pseudocode and Runtime Analysis
Your submission should be formatted in a double-spaced 1- to 2-page Word 
document that includes your completed pseudocode, your runtime analysis in a 
chart, and your analysis of both the advantages and disadvantages of each 
structure.
___

# Module 3: Vector Pseudocode
```
CLASS Course {
    DECLARE STRING id
    DECLARE STRING title
    DECLARE VECTOR<STRING> prerequisites
}

vector<Course> LoadCourseData(fileName) {

    DECLARE vector<Course> courses

    // Attempt to open a file
    TRY
        OPEN file "data_file.txt"
    CATCH
        PRINT "Error: Failed to open data file"
        RETURN empty vector
    END TRY

    // Loop through the lines of the file
    WHILE there are still lines of code in the file to be read THEN

        READ next line

        IF line contains no text THEN CONTINUE

        DECLARE lineTokens = SPLIT line by comma

        IF lineTokens size is less than 2 THEN 
            PRINT "Error: Invalid line. Must have at least 2 tokens"
            CLOSE file
            RETURN empty vector 
        END IF

        DECLARE courseNumber = lineTokens[0]
        DECLARE courseTitle = lineTokens[1]
        DECLARE prereqs = VECTOR of strings

        IF courseNumber is empty OR courseTitle is empty THEN 
            PRINT "Error: Invalid course number or title on line " + lineNumber
            CLOSE file
            RETURN empty vector 
        END IF
        
        // Store course number for later prerequisite validation
        DECLARE count = 2 
        WHILE count < size of lineTokens THEN

            PUSH lineTokens[count] into prereqs
            INCREMENT count up by 1

        END WHILE

        DECLARE courseObject = Course {
            id = courseId,
            title = courseTitle,
            prerequisites = prereqs
        }

        PUSH courseObject into courses vector 

    END WHILE

    RETURN courses

}


bool ValidateCourses(courseVector) {
    IF courseVector size is greater than 0 THEN 
        RETURN TRUE
    ELSE
        RETURN FALSE
    END IF
}


void main() {

    DECLARE vec<Course> courses = LoadCourseData()
    DECLARE bool isValid = ValidateCourses(courses)
    DECLARE bool breakCondition = FALSE

    PRINT "Enter a course ID number to search for"

    WHILE NOT breakCondition THEN 

        DECLARE userInput = GET user input
        
        IF userInput == "q" THEN 
            
            breakCondition = true
            CONTINUE
        
        END IF

        IF isValid THEN 

            FOR EACH course in courses vector THEN 

                IF course.courseId == userInput THEN 
                    
                    PRINT course.id
                    PRINT course.title
                    
                    FOR EACH preReq in course.prerequisites THEN 
                        
                        PRINT preReq
                    
                    END FOR
                
                END IF

            END FOR

        END IF
    
    END WHILE

}
```
___

# Module 4: Hash Table Pseudocode
```
CLASS Course {
    DECLARE STRING id
    DECLARE STRING title
    DECLARE VECTOR<STRING> prerequisites
}

CLASS HashTable {
    DECLARE INT tableSize
    DECLARE VECTOR<Course> courses 
}

INT hashString(string inputString) {

    INT multiplierValue = 31
    INT hashValue = 0

    FOR each character in the input string

        // Convert each individual character into a numerical value
        INT charToInt = characters utf8 value
        hashValue = hashValue * multiplierValue + charToInt 

    END FOR

    RETURN hashValue

}

HashTable<INT, Course> LoadCourseData(fileName) {

    DECLARE hashTable = HashTable<INT, Course> 

    // Attempt to open a file
    TRY
        OPEN file "data_file.txt"
    CATCH
        PRINT "Error: Failed to open data file"
        RETURN empty hash table 
    END TRY

    // Loop through the lines of the file
    WHILE there are still lines of code in the file to be read THEN

        READ next line

        IF line contains no text THEN CONTINUE

        DECLARE lineTokens = SPLIT line by comma

        IF lineTokens size is less than 2 THEN 
            PRINT "Error: Invalid line. Must have at least 2 tokens"
            CLOSE file
            RETURN empty hash table 
        END IF

        DECLARE courseNumber = lineTokens[0]
        DECLARE courseTitle = lineTokens[1]
        DECLARE prereqs = VECTOR of strings

        IF courseNumber is empty OR courseTitle is empty THEN 
            PRINT "Error: Invalid course number or title on line " + lineNumber
            CLOSE file
            RETURN empty hash table 
        END IF
        
        // Store course number for later prerequisite validation
        DECLARE count = 2 
        WHILE count < size of lineTokens THEN

            PUSH lineTokens[count] into prereqs
            INCREMENT count up by 1

        END WHILE

        DECLARE courseObject = Course {
            id = courseId,
            title = courseTitle,
            prerequisites = prereqs
        }

        DECLARE hashKey = hashString(courseId)
        ASSIGN hashTable[hashKey] = courseObject

    END WHILE

    RETURN courses

}


void main() {

    DECLARE HashTable courses = LoadCourseData()
    DECLARE bool breakCondition = FALSE

    PRINT "Enter a course ID number to search for"

    WHILE NOT breakCondition THEN 

        DECLARE userInput = GET user input
        
        IF userInput == "q" THEN 
            
            breakCondition = true
            CONTINUE
        
        END IF

        IF courses.tableSize > 0 THEN 

            TRY
                DECLARE Course course = courses[userInput]

                IF course.courseId == userInput THEN 
                    
                    PRINT course.id
                    PRINT course.title
                    
                    FOR EACH preReq in course.prerequisites THEN 
                        
                        PRINT preReq
                    
                    END FOR
                
                END IF
            
            EXCEPT Key Error
                PRINT "Error: Invalid HashTable key"

        END IF
    
    END WHILE

}
```
___

# Module 5: Binary Tree Pseudocode
```
CLASS Course {
    DECLARE STRING id
    DECLARE STRING title
    DECLARE VECTOR<STRING> prerequisites
}

CLASS Node {
    DECLARE Course course
    DECLARE Node* left
    DECLARE Node* right
}

CLASS BTree {
    DECLARE Node* root = null 
}

// Class method for inserting new nodes
BTree::Insert(Course course) {
    
    IF root is null THEN
        root = node
        RETURN 
    ELSE 
        BTree::addNode(root, course)
    END IF

}

BTree::addNode(Node* node, Course course) {

    IF course.id < node.course.id THEN
        IF node.left is null THEN
            node.left = Node(course)
        ELSE 
            addNode(node.left, course)
        END IF
    ELSE IF course.id > node.course.id THEN
        IF node.right is null THEN
            node.right = Node(course)
        ELSE
            addNode(node.right, course)
        END
    END IF

}

Course* BTree::Search(courseId) {
    
    Node* node = root

    WHILE node is not null THEN 
        
        IF node.course.id == courseId THEN 
            RETURN &node.course
        ELSE 
            IF node.course.id < courseID THEN 
                node = node.left
            ELSE
                node = node.right
            END IF 
        END IF 
    
    END WHILE

    RETURN nullptr 

}

BTree<INT, Course> LoadCourseData(fileName) {

    DECLARE btree = BTree 

    // Attempt to open a file
    TRY
        OPEN file "data_file.txt"
    CATCH
        PRINT "Error: Failed to open data file"
        RETURN empty hash table 
    END TRY

    // Loop through the lines of the file
    WHILE there are still lines of code in the file to be read THEN

        READ next line

        IF line contains no text THEN CONTINUE

        DECLARE lineTokens = SPLIT line by comma

        IF lineTokens size is less than 2 THEN 
            PRINT "Error: Invalid line. Must have at least 2 tokens"
            CLOSE file
            RETURN empty hash table 
        END IF

        DECLARE courseNumber = lineTokens[0]
        DECLARE courseTitle = lineTokens[1]
        DECLARE prereqs = VECTOR of strings

        IF courseNumber is empty OR courseTitle is empty THEN 
            PRINT "Error: Invalid course number or title on line " + lineNumber
            CLOSE file
            RETURN empty hash table 
        END IF
        
        // Store course number for later prerequisite validation
        DECLARE count = 2 
        WHILE count < size of lineTokens THEN

            PUSH lineTokens[count] into prereqs
            INCREMENT count up by 1

        END WHILE

        DECLARE courseObject = Course {
            id = courseId,
            title = courseTitle,
            prerequisites = prereqs
        }

        // Build tree from course objects
        btree.Insert(courseObject)

    END WHILE

    RETURN courses

}


void main() {

    DECLARE BTree courses = LoadCourseData()
    DECLARE bool breakCondition = FALSE

    PRINT "Enter a course ID number to search for"

    WHILE NOT breakCondition THEN 

        DECLARE userInput = GET user input
        
        IF userInput == "q" THEN 
            
            breakCondition = true
            CONTINUE
        
        END IF

        DECLARE Course* course = courses.Search(userInput)

        IF course is NOT null THEN
            
            DISPLAY course.id
            DISPLAY course.title

            FOR EACH prerequisite IN course.prerequisites THEN
                DISPLAY prerequisite
            END FOR

        END IF
       
    END WHILE

}
```

___

# Menu Pseudocode:

```
FUNCTION MAIN_MENU()

    DECLARE dataLoaded = FALSE
    DECLARE userChoice

    WHILE userChoice != 9

        DISPLAY menu

        DISPLAY "1. Load Data Structure"
        DISPLAY "2. Print Course List"
        DISPLAY "3. Print Course"
        DISPLAY "9. Exit"

        INPUT userChoice

        SWITCH userChoice

            CASE 1

                courses = LoadCourseData(fileName)
                dataLoaded = TRUE

            CASE 2

                IF dataLoaded
                    PrintCourseList()
                ELSE
                    DISPLAY "Please load data first"
                END IF

            CASE 3

                IF dataLoaded

                    DISPLAY "Enter course number"
                    INPUT courseId

                    PrintCourse(courseId)

                ELSE
                    DISPLAY "Please load data first"
                END IF

            CASE 9

                DISPLAY "Goodbye"

            DEFAULT

                DISPLAY "Invalid option"

        END SWITCH

    END WHILE
```

# Printing Course ID Functions
The following functions print course information in alphanumeric order, 
depending on the data type.

## Vector
### Pseudocode
```
FUNCTION printCourses(vector<Course> courses) {

    SORT courses in vector by course.id with quick sort algorithm

    FOR EACH course in courses vector

        DISPLAY course.id + ", " + course.title

    END FOR 

}
```

### Evaluation

| Code                           | Line Cost  | Execution Times  | Total Cost |
|--------------------------------|------------|------------------|------------|
| Sort vector with quick sort    | O(n log n) | 1                | O(n log n) |
| For each course                | 1          | n                | n          |
| Display course info            | 1          | n                | n          |

**Total Cost:** O(n log n) + 2n
**Runtime:** O(n log n)


## Hash Table 
### Pseudocode
```
FUNCTION printCourses(HashTable<INT, Course> courses) {

    DECLARE tempVector

    FOR EACH bucket IN hashTable

        FOR EACH course IN bucket

            ADD course TO tempVector

        END FOR

    END FOR

    SORT tempVector by course.id with qiuck sort algorithm

    FOR EACH course IN tempVector

        DISPLAY course.id + ", " + course.title

    END FOR
}
```

### Evaluation

| Code                           | Line Cost  | Execution Times  | Total Cost |
|--------------------------------|------------|------------------|------------|
| Create temp vector             | 1          | n                | n          |
| For each bucket in hash table  | 1          | n                | n          | 
| For each course in bucket      | 1          | n                | n          |
| Add course to temp vector      | 1          | n                | n          |
| Sort temp vector               | O(n log n) | 1                | O(n log n) |
| For each course in temp vec    | 1          | n                | n          |
| Display course info            | 1          | n                | n          |

**Total Cost:** O(n log n) + 5n + 1 
**Runtime:** O(n log n) 


## Binary Search Tree 
### Pseudocode
```
FUNCTION printCourses(BinarySearchTree courses) {
    
    InOrderTraversal(courses.root)

}

FUNCTION InOrderTraversal(Node node) {

    IF node IS null
        RETURN
    END IF

    InOrderTraversal(node.left)

    DISPLAY node.course.id + ", " + node.course.title

    InOrderTraversal(node.right)

}
```

### Evaluation

| Code                           | Line Cost  | Execution Times  | Total Cost |
|--------------------------------|------------|------------------|------------|
| If node is null                | 1          | n + 1            | 1          |
| Recurse down left branch       | 1          | n                | n          |
| Display course information     | 1          | n                | n          |
| Recruse down right branch      | 1          | n                | n          |

**Total Cost:** 4n + 1 
**Runtime:** O(n) 



