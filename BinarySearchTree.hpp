#pragma once
#include <string>
#include "Course.hpp"

//============================================================================
// Binary Search Tree class definition
//============================================================================

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================


// Internal structure for tree node
struct Node {
    Course course;
    Node *left;
    Node *right;

    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    // initialize with a course
    Node(Course aCourse) : Node() {
        course = aCourse;
    }
};


/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    Node* removeNode(Node* node, std::string courseId);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void PostOrder();
    void PreOrder();
    void Insert(Course course);
    void Remove(std::string courseId);
    Course Search(std::string courseId);
};


void loadCourses(std::string csvPath, BinarySearchTree* bst); 
void displayCourseData(std::string courseId, BinarySearchTree* bst);


