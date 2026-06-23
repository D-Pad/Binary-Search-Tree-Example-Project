#pragma once 
#include <string>
#include <vector>


class Course {

private:
    std::string courseId;
    std::string title; 
    std::vector<std::string> prerequisites;    

public: 
    
    Course();
    Course(
        std::string courseId, 
        std::string title
    );
    Course(
        std::string courseId, 
        std::string title,
        std::vector<std::string> prerequisites
    );
    
    void addPrerequisite(std::string prerequisite);
    bool isValid();
   
    // Getters
    std::string getCourseId();
    std::string getTitle();
    std::vector<std::string>* getPrerequisites();
    
};

