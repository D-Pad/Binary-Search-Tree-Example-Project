# Project Two: Binary Search Tree
This repo contains my assignment for project 1, as well as all of the source 
code that was used to build project 2 in my CS-300 course. The easiest way to 
compile and run the project is on a Linux system with the `./build.sh` script.
Otherwise, use cmake on a Windows system to compile and run it yourself.


## Q&A Section:

**Q:** What was the problem you were solving in the projects for this course?  
 - **A:** It's difficult for me to image this class as a "problem solving" 
   experience because I wasn't really tasked with an issue to solve. It was 
   more of a learning experience on how different data structures and 
   algorithms work under the hood. This was incredibly value to me. I use 
   Hash Tables and even Binary Trees quite often in Rust programming, but 
   until now, I had no idea what made them different from each other. All I 
   knew was that if the insertion order was import to me, then I needed a 
   Binary Tree, and if ordering wasn't important, then I'd use a Hash Map. If
   I had to explicitly define a problem, then I guess I'd have to say that I 
   needed to find the appropriate algorithm or data structure for each task 
   that was assigned to me.

**Q:** How did you approach the problem? Consider why data structures are 
important to understand.
 - **A:** The way that I approached the problem was by first trying to 
   understand what data structure would be best for any given task. At the 
   start of the class, I learned why arrays and vectors can be slow to lookup 
   data, and also slow to insert data when attempting to insert data 
   somewhere in the middle of the structure. This is because the data of an 
   array is contiguous in memory, and it may be necessary to copy all values of
   the structure to another location with enough available memory. Also, when
   inserting in the middle, the second half of the vector/array needs to be 
   shifted.

   Then I learned about Linked Lists, Binary Trees, and Hash Maps. Each of 
   these have strengths and weaknesses of their own. On my last assignment, 
   I chose to use a Binary Search Tree because they preserve ordering, have
   fast insertion times, and equally fast search times, which makes it a 
   perfect candidate for storing course ID's and prerequisites of each class.

**Q:** How did you overcome any roadblocks you encountered while going 
through the activities or project?
 - **A:** I tend to overcome all coding challenges the same way, which is to 
   stop what I'm doing, and start researching when I feel confused. A good 
   example was trying to implement my own CSV file parser function in project 2 
   rather than using the `CsvParser.cpp` file that was provided to me several
   times throughout the duration of the course. I didn't have much experience
   reading files in C++, so I had to stop and do some research on how to 
   actually open a file and read it line by line. Higher level languages like 
   Python make reading file data trivial. There were many more steps involved
   in C++.

**Q:** How has your work on this project expanded your approach to designing 
software and developing programs?
 - **A:** I've got several years of experience as a full stack developer, and 
   until now, I've hardly ever thought about which data structure would be 
   the most efficient tool for any particular task. Normally I just create a 
   custom class if I need to store related data, and I would always use 
   vectors or key-value pairs if I ever needed to group specific bits of data
   together. Now, I feel like I'm more prepared to analyze performance impact
   of any one particular structure, which will help me to write more efficient
   applications.

**Q:** How has your work on this project evolved the way you write programs 
that are maintainable, readable, and adaptable?
 - **A:** Honestly, I don't think this class has changed much about how I 
   structure my projects or write code, but I do believe that it's put me in a 
   position to write more high performant code. Low level backend development
   is my favorite thing to do as a developer, and this course has taught me a 
   lot of new tricks in that regard.


