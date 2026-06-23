#include <iostream> 
#include <string>
#include "BinarySearchTree.hpp"


void displayMenu() {

    std::cout
        << std::endl
        << "  1. Load Data Structure" << std::endl
        << "  2. Print Course List" << std::endl 
        << "  3. Print Course" << std::endl 
        << "  9. Exit" << std::endl << std::endl
        << "What would you like to do? ";

}

int main(int argc, char* argv[]) {

    // Load command line arguments, if any were passed. Otherwise, set the 
    // default CSV path
    std::string csvPath;
    switch (argc) {
        case 2:
            csvPath = argv[1];
            break;
        default:
            csvPath = "CS 300 ABCU_Advising_Program_Input.csv";
    }

    // Initialize a variable for storing the user choice
    int choice = 0;
    std::string searchId = "";

    // Initialize the data structure. I don't see much point in making this 
    // a pointer type like in prior assignments.
    BinarySearchTree bst = BinarySearchTree();

    // Start main loop
    while (choice != 9) {

        // Display options for the user. Do this on every loop so that it 
        // doesn't get buried in the terminal after making selections
        displayMenu();
  
        std::cin >> choice;

        switch(choice) {

            case 1:
                loadCourses(csvPath, &bst); 
                break;

            case 2:
                std::cout << "Here is a sample schedule:" 
                    << std::endl << std::endl;
                bst.InOrder(); 
                break;

            case 3:
                // Prompt the user for a course ID to search for. 
                std::cout 
                   << std::endl << "Which course do you want to know about? ";
                
                std::cin >> searchId;
                displayCourseData(searchId, &bst);
                searchId = "";
                break;

            case 9:
                std::cout << "Thank you for using the course planner!" 
                    << std::endl;
                break;

            default:
                std::cerr << choice << " is not a valid option" << std::endl;

        }

    }

}   
