#include <iostream>
#include <algorithm>
#include <cctype>
#include "CSVparser.hpp"
#include "Course.hpp"
#include "BinarySearchTree.hpp"   

using namespace std;

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr; 
}


/**
 * Helper function for deleting all nodes during destruction
 */
void destroy(Node* node) {

    if (node == nullptr) {
        return;
    }

    // Recursively destroy child nodes then self
    destroy(node->left);
    destroy(node->right);
    delete node;

}


/*
 * Helper function for comparing course ID's. In case a course ID has fewer
 * text characters than another, such as comparing CS50 to CS100. String
 * comparisons in C++ are lexigraphical, and this comparison would show 
 * CS50 as being greater than CS100
 */
bool aIsLessThanOrEqualToB(std::string courseA, std::string courseB) {

    if (courseA.size() < courseB.size()) {
        return true;
    }

    else if (courseA.size() == courseB.size()) {
        return courseA <= courseB; 
    }

    return false;
}


/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // Call the 'destroy' helper function which recursively removes all nodes. 
    destroy(root);
}


/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    inOrder(root); 
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    preOrder(root);
}



/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
    if (root == nullptr) {
        root = new Node(course); 
    }
    else {
        addNode(root, course); 
    }
}

/**
 * Remove a course
 */
void BinarySearchTree::Remove(string courseId) {
    // Use removeNode method to delete nodes from the tree.
    removeNode(root, courseId);
}

/**
 * Search for a course
 */
Course BinarySearchTree::Search(string courseId) {

    Node* curr = root;
    Course course = Course();

    while (curr != nullptr) {

        std::string thisCourseId = curr->course.getCourseId();
        bool traverseLeft = aIsLessThanOrEqualToB(courseId, thisCourseId);

        // If the current nodes course ID matches, then return the course
        if (thisCourseId == courseId) {
            course = curr->course;
            return course;
        }

        // Otherwise, move left or right depending on the value of the course 
        // ID.
        if (curr->left != nullptr && traverseLeft) {
            curr = curr->left;
        }
        else if (curr->right != nullptr && !traverseLeft) {
            curr = curr->right;
        }
        else {
            break;
        }
    }

    return course;

}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void BinarySearchTree::addNode(Node* node, Course course) {

    // If the current course title is less than the node course title, then 
    // traverse the left side
    if (course.getCourseId() < node->course.getCourseId()) {
        
        // If the left node is empty, then insert on the left 
        if (node->left == nullptr) {
            node->left = new Node(course); 
        }
        else {
            addNode(node->left, course);
        }
    }
    // Otherwise, if the current course is greater than the node course 
    // courseId, then traverse the right side
    else if (course.getCourseId() > node->course.getCourseId()) {

        // If the right node is empty, then insert on the right
        if (node->right == nullptr) {
            node->right = new Node(course);
        }
        else {
            addNode(node->right, course);
        }
    };

}

void BinarySearchTree::inOrder(Node* node) {

    if (node == nullptr) {
        return;
    }

    // Search the left most nodes first
    inOrder(node->left);

    // Display node information
    cout << node->course.getCourseId() << ", "
        << node->course.getTitle() << endl;

    // Search right node
    inOrder(node->right);

}

void BinarySearchTree::postOrder(Node* node) {

    if (node != nullptr) {

        // Display node information
        cout << node->course.getCourseId() << " | "
            << node->course.getTitle() << endl;

        preOrder(node->left);
        preOrder(node->right);

    }

}

void BinarySearchTree::preOrder(Node* node) {

    if (node != nullptr) {

        postOrder(node->right);
        postOrder(node->left);
        cout << node->course.getCourseId() << endl;

    }

}

/**
 * Remove a course from some node (recursive)
 */
Node* BinarySearchTree::removeNode(Node* node, string courseId) {
    
    // If the passed node is a null pointer, then the bottom has been reached.
    // Return.
    if (node == nullptr) {
        return node;
    }

    // Check to see if we need to traverse further into the tree. If no match 
    // was found, then we need to determine which way to traverse. If the 
    // current node's course Id is smaller than the node course ID, then we 
    // need to move left. If the course ID is larger, then we need to move 
    // right.
    if (courseId < node->course.getCourseId()) {
        node->left = removeNode(node->left, courseId);
    }

    else if (courseId > node->course.getCourseId()) {
        node->right = removeNode(node->right, courseId);
    }

    // If the node is found, then determine how to handle the deletion 
    // based on the number of child nodes.
    else {
       
        // Case 1: Leaf node (no children)
        if (node->left == nullptr && node->right == nullptr) {
            
            // Delete the node and return a null pointer
            delete node;
            return nullptr;
        }

        // Case 2: Node has only one child 
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        else if(node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Case 3: Node has 2 children 
        else {

            // If there is only 1 child then find the smallest node in the 
            // right sub tree
            Node* temp = node->right;

            // Look for the smallest node
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            // Copy the successor data into the 'current' node
            node->course = temp->course;

            // Delete duplicate successor node.
            node->right = removeNode(node->right, temp->course.getCourseId());

        }

    }

    return node;
}

/**
 * Load a CSV file containing courses into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the courses read
 */
void loadCourses(string csvPath, BinarySearchTree* bst) {
    
    /*
     * MATH201,Discrete Mathematics,,
     * CSCI300,Introduction to Algorithms,CSCI200,MATH201
     * CSCI350,Operating Systems,CSCI300,
     * CSCI101,Introduction to Programming in C++,CSCI100,
     * CSCI100,Introduction to Computer Science,,
     * CSCI301,Advanced Programming in C++,CSCI101,
     * CSCI400,Large Software Development,CSCI301,CSCI350
     * CSCI200,Data Structures,CSCI101,
     */

    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of courses
            Course course = Course(file[i][0], file[i][1]);
            
            string prereq1 = file[i][2];
            string prereq2 = file[i][3];

            if (prereq1 != "") {
                course.addPrerequisite(prereq1);
            }

            if (prereq2 != "") {
                course.addPrerequisite(prereq2);
            }

            bst->Insert(course);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}


void displayCourseData(std::string courseId, BinarySearchTree* bst) {
 
    // Convert the course ID into upper case using std::transform and 
    // std::toupper from the <algorithm> and <cctype> modules.
    std::transform(courseId.begin(), courseId.end(), courseId.begin(),
        [](unsigned char c) { return std::toupper(c); });

    // Search for the course
    Course course = bst->Search(courseId);

    // Check to see if the course has a valid ID and title
    if (course.isValid()) {
        std::cout
            << course.getCourseId() << ", " 
            << course.getTitle() << std::endl 
            << "Prerequisites: ";

        std::vector<std::string>* prereqs = course.getPrerequisites();
        int numPrereqs = prereqs->size();       

        // If the course has prerequisites, then show them
        if (prereqs->size() > 0) {
            
            for (int i = 0; i < numPrereqs; i++) {
                
                Course prereq = bst->Search(prereqs->at(i));
                std::cout << prereq.getCourseId();
                if (i < numPrereqs - 1) {
                    std::cout << ", ";
                }
            
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "    None" << std::endl;
        }
    }

    else {
        std::cout 
            << "Course ID '" << courseId 
            << "' does not exist." << std::endl;
    }

};

